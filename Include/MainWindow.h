#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}

class QSettings;

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void InvokeGenerate();


private:
    void Init() noexcept;
    void InitConnect() noexcept;

    Ui::MainWindow *ui;
    QSettings* settings_{nullptr};
};
