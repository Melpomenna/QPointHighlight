#pragma once

#include <Domain/UIData.h>
#include <QWidget>

namespace Core::Interfaces
{
    class IRenderable;
}

/**
 * @class RenderWidget
 * @brief A widget for rendering graphical objects and handling mouse events.
 *
 * This class extends QWidget to provide custom rendering functionality
 * and mouse event handling. It interacts with objects implementing the
 * IRenderable interface and emits signals for mouse interactions.
 */
class RenderWidget final : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Constructs a RenderWidget.
     * @param parent The parent widget, or nullptr if no parent.
     */
    explicit RenderWidget(QWidget* parent = nullptr);

    /**
     * @brief Destructor for RenderWidget.
     */
    ~RenderWidget() override = default;

    /**
     * @brief Handles the paint event to render the object.
     * @param event Pointer to the QPaintEvent containing painting details.
     */
    void paintEvent(QPaintEvent* event) override;

    /**
     * @brief Handles mouse press events.
     * @param event Pointer to the QMouseEvent containing event details.
     */
    void mousePressEvent(QMouseEvent* event) override;

    /**
     * @brief Handles mouse move events.
     * @param event Pointer to the QMouseEvent containing event details.
     */
    void mouseMoveEvent(QMouseEvent* event) override;

    /**
     * @brief Handles mouse release events.
     * @param event Pointer to the QMouseEvent containing event details.
     */
    void mouseReleaseEvent(QMouseEvent* event) override;

signals:
    /**
     * @brief Emitted when the widget is clicked.
     * @param point The 2D point where the click occurred.
     */
    void clicked(Core::Data::Point2D point);

    /**
     * @brief Emitted when the mouse is moved.
     * @param point The 2D point where the mouse moved.
     */
    void move(Core::Data::Point2D point);

    /**
     * @brief Emitted when the mouse button is released.
     * @param point The 2D point where the release occurred.
     */
    void release(Core::Data::Point2D point);

public slots:
    /**
     * @brief Updates the view with a new renderable object.
     * @param renderObject A shared pointer to the renderable object.
     */
    void UpdateView(std::shared_ptr<Core::Interfaces::IRenderable> renderObject);

private:
    /**
     * @brief The renderable object to be drawn.
     */
    std::shared_ptr<Core::Interfaces::IRenderable> object_{nullptr};
};
