#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <ArchitectureCore/GenerateAreaController.h>
#include <ArchitectureCore/GenerateAreaModel.h>
#include <ArchitectureCore/GeneratePointsController.h>
#include <ArchitectureCore/GeneratePointsModel.h>
#include <QSettings.h>
#include <QStringListModel>
#include <RenderWidget.h>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent), ui(new Ui::MainWindow),
    settings_(new QSettings("Settings.ini", QSettings::Format::IniFormat, this))
{
    ui->setupUi(this);

    Init();
    InitConnect();
}

void MainWindow::Init() noexcept
{
    ui->PointRadiusSpinBox->setValue(settings_->value("points-radius", DEFAULT_AREA_RADIUS).toInt());
    ui->PointsGenerateCountSpinBox->setValue(settings_->value("points-count", DEFAULT_POINTS_COUNT).toInt());
}

void MainWindow::InitConnect() noexcept
{
    auto pointGenerateModel = new Core::ArchitectureCore::GeneratePointsModel(this);
    auto pointGenerateController = new Core::ArchitectureCore::GeneratePointsController(
        generatePointsContext_.MakeShared(), pointGenerateModel, this);

    auto areaGenerateModel = new Core::ArchitectureCore::GenerateAreaModel(pointGenerateModel, this);
    auto areaGenerateController = new Core::ArchitectureCore::GenerateAreaController(
        generatePointsContext_.MakeShared(), areaGenerateModel, this);

    connect(ui->GeneratePointsButton, &QPushButton::clicked, this, &MainWindow::InvokeGenerate);
    connect(pointGenerateController, &Core::Interfaces::IController::OnFinished, ui->RenderViewWidget,
            &RenderWidget::UpdateView);


    connect(this, &MainWindow::ControlGeneratePointsData, pointGenerateController,
            &Core::Interfaces::IController::OnControl);

    connect(ui->RenderViewWidget, &RenderWidget::clicked, this, &MainWindow::OnStartGenerateArea);
    connect(ui->RenderViewWidget, &RenderWidget::clicked, areaGenerateController,
            &Core::Interfaces::IAreaController::OnStartControl);
    connect(ui->RenderViewWidget, &RenderWidget::move, areaGenerateController,
            &Core::Interfaces::IAreaController::OnControl);
    connect(ui->RenderViewWidget, &RenderWidget::release, this, &MainWindow::FinishGenerateArea);
    connect(this, &MainWindow::ControlFinishGenerateArea, areaGenerateController,
            &Core::Interfaces::IAreaController::OnFinishedControl);

    connect(areaGenerateController, &Core::Interfaces::IAreaController::OnFinishedRecalcArea, this,
            &MainWindow::OnFinishedRecalcArea);
    connect(areaGenerateController, &Core::Interfaces::IAreaController::OnFinishedPart, ui->RenderViewWidget,
            &RenderWidget::UpdateView);
    connect(areaGenerateController, &Core::Interfaces::IAreaController::OnFinished, ui->RenderViewWidget,
            &RenderWidget::UpdateView);
    connect(areaGenerateController, &Core::Interfaces::IAreaController::OnFinished, this,
            &MainWindow::OnFinishGenerateArea);
}

MainWindow::~MainWindow()
{
    settings_->setValue("points-radius", ui->PointRadiusSpinBox->value());
    settings_->setValue("points-count", ui->PointsGenerateCountSpinBox->value());

    delete ui;
}

void MainWindow::InvokeGenerate()
{
    if (ui->PointsAreasListView->model())
        ui->PointsAreasListView->model()->removeRows(0, ui->PointsAreasListView->model()->rowCount());
    emit ControlGeneratePointsData(CollectUIData());
}

void MainWindow::FinishGenerateArea(Core::Data::Point2D endPos)
{
    emit ControlFinishGenerateArea(endPos, CollectUIData());
}

void MainWindow::OnStartGenerateArea(Core::Data::Point2D)
{
    ui->GeneratePointsButton->setDisabled(true);
}

void MainWindow::OnFinishGenerateArea(std::shared_ptr<Core::Interfaces::IRenderable>)
{
    ui->GeneratePointsButton->setDisabled(false);
}

_NODISCARD Core::Data::UIDataInput MainWindow::CollectUIData() const noexcept
{
    Core::Data::UIDataInput uiData{};
    uiData.generatePointsCount_ = ui->PointsGenerateCountSpinBox->value();
    uiData.pointsRadius_ = ui->PointRadiusSpinBox->value();
    uiData.windowHeight_ = ui->RenderViewWidget->width() - DEFAULT_POINTS_RADIUS;
    uiData.windowWidth_ = ui->RenderViewWidget->height() - DEFAULT_POINTS_RADIUS;
    return uiData;
}

void MainWindow::OnFinishedRecalcArea(std::pmr::vector<Core::Data::CapturedAreas> capturedAreas)
{
    QStringList list;
    for (std::size_t i = 0; i < capturedAreas.size(); ++i)
        list.push_back(
            QString::asprintf("%s: count: %llu", capturedAreas[i].label_.data(), capturedAreas[i].pointCount_));
    QStringListModel* model = new QStringListModel(list);
    ui->PointsAreasListView->setModel(model);
}
