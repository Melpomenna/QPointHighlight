#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <Domain/UIData.h>
#include <QSettings.h>

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
    ui->PointRadiusSpinBox->setValue(settings_->value("points-radius", DEFAULT_POINTS_RADIUS).toInt());
    ui->PointsGenerateCountSpinBox->setValue(settings_->value("points-count", DEFAULT_POINTS_COUNT).toInt());
}

void MainWindow::InitConnect() noexcept
{
    connect(ui->GeneratePointsButton, &QPushButton::clicked, this, &MainWindow::InvokeGenerate);
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
}
