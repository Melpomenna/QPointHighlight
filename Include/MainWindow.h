#pragma once

#include <Async/Context.h>
#include <Domain/UIData.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}

class QSettings;

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

signals:
    void ControlGeneratePointsData(Core::Data::UIDataInput);

public slots:
    void InvokeGenerate();


private:
    void Init() noexcept;
    void InitConnect() noexcept;

    Ui::MainWindow* ui;
    QSettings* settings_{nullptr};
    Core::Async::Context generatePointsContext_;
};
