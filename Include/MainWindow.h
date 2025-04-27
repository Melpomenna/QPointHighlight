#pragma once

#include <Async/Context.h>
#include <Domain/UIData.h>
#include <QMainWindow>

namespace Core::Interfaces
{
    class IRenderable;
}

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
    void ControlFinishGenerateArea(Core::Data::Point2D, Core::Data::UIDataInput);

public slots:
    void InvokeGenerate();
    void OnStartGenerateArea(Core::Data::Point2D);
    void OnFinishGenerateArea(std::shared_ptr<Core::Interfaces::IRenderable>);
    void FinishGenerateArea(Core::Data::Point2D);
    void OnFinishedRecalcArea(std::pmr::vector<Core::Data::CapturedAreas>);

private:
    void Init() noexcept;
    void InitConnect() noexcept;
    _NODISCARD Core::Data::UIDataInput CollectUIData() const noexcept;

    Ui::MainWindow* ui;
    QSettings* settings_{nullptr};
    Core::Async::Context generatePointsContext_;
};
