#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <ArchitectureCore/GeneratePointsController.h>
#include <ArchitectureCore/GeneratePointsModel.h>
#include <QSettings.h>
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
    auto pointGenerateController =
        new Core::ArchitectureCore::GeneratePointsController(generatePointsContext_.MakeShared(), pointGenerateModel, this);

    connect(ui->GeneratePointsButton, &QPushButton::clicked, this, &MainWindow::InvokeGenerate);
    connect(pointGenerateController, &Core::Interfaces::IController::OnFinished, ui->RenderViewWidget,
            &RenderWidget::UpdateView);


    connect(this, &MainWindow::ControlGeneratePointsData, pointGenerateController,
            &Core::Interfaces::IController::OnControl);
}

MainWindow::~MainWindow()
{
    settings_->setValue("points-radius", ui->PointRadiusSpinBox->value());
    settings_->setValue("points-count", ui->PointsGenerateCountSpinBox->value());

    delete ui;
}

void MainWindow::InvokeGenerate()
{
    Core::Data::UIDataInput uiData{};
    uiData.generatePointsCount_ = ui->PointsGenerateCountSpinBox->value();
    uiData.pointsRadius_ = ui->PointRadiusSpinBox->value();
    uiData.windowHeight_ = ui->RenderViewWidget->width() - DEFAULT_POINTS_RADIUS;
    uiData.windowWidth_ = ui->RenderViewWidget->height() - DEFAULT_POINTS_RADIUS;
    emit ControlGeneratePointsData(uiData);
}
