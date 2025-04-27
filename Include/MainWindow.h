#pragma once

#include <Async/Context.h>
#include <Domain/UIData.h>
#include <QMainWindow>

namespace Core::Interfaces
{
    /**
    * @class IRenderable
    * @brief An interface for objects that can be rendered.
    *
    * This interface provides a contract for objects that need to implement
    * custom rendering logic using a QPaintEvent and a QPaintDevice.
    */
    class IRenderable;
}

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}

class QSettings;

QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief The main application window.
 *
 * This class represents the main window of the application, providing
 * the user interface and handling user interactions.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor.
     * @param parent The parent widget, or nullptr if none.
     */
    explicit MainWindow(QWidget* parent = nullptr);

    /**
     * @brief Destructor.
     */
    ~MainWindow();

signals:
    /**
     * @brief Signal emitted to generate points data.
     * @param input The input data for generating points.
     */
    void ControlGeneratePointsData(Core::Data::UIDataInput input);

    /**
     * @brief Signal emitted when area generation is finished.
     * @param point The point where the area generation finished.
     * @param input The input data used for generating the area.
     */
    void ControlFinishGenerateArea(Core::Data::Point2D point, Core::Data::UIDataInput input);

public slots:
    /**
     * @brief Slot to invoke the generation process.
     */
    void InvokeGenerate();

    /**
     * @brief Slot called when area generation starts.
     * @param point The starting point of the area generation.
     */
    void OnStartGenerateArea(Core::Data::Point2D point);

    /**
     * @brief Slot called when area generation finishes.
     * @param renderable A shared pointer to the renderable object.
     */
    void OnFinishGenerateArea(std::shared_ptr<Core::Interfaces::IRenderable> renderable);

    /**
     * @brief Finalizes the area generation process.
     * @param point The point where the area generation finished.
     */
    void FinishGenerateArea(Core::Data::Point2D point);

    /**
     * @brief Slot called when area recalculation is finished.
     * @param capturedAreas A vector of captured areas.
     */
    void OnFinishedRecalcArea(std::pmr::vector<Core::Data::CapturedAreas> capturedAreas);

private:
    /**
     * @brief Initializes the main window.
     */
    void Init() noexcept;

    /**
     * @brief Sets up signal-slot connections.
     */
    void InitConnect() noexcept;

    /**
     * @brief Collects user interface data.
     * @return The collected UI data.
     */
    _NODISCARD Core::Data::UIDataInput CollectUIData() const noexcept;

    Ui::MainWindow* ui; ///< Pointer to the UI object.
    QSettings* settings_{nullptr}; ///< Pointer to the application settings.
    Core::Async::Context generatePointsContext_; ///< Context for generating points.
};
