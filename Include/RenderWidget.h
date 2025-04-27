#pragma once

#include <Domain/UIData.h>
#include <QWidget>

namespace Core::Interfaces
{
    class IRenderable;
}

class RenderWidget final : public QWidget
{
    Q_OBJECT
public:
    explicit RenderWidget(QWidget* parent = nullptr);
    ~RenderWidget() override = default;

    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

signals:
    void clicked(Core::Data::Point2D);
    void move(Core::Data::Point2D);
    void release(Core::Data::Point2D);

public slots:
    void UpdateView(std::shared_ptr<Core::Interfaces::IRenderable> renderObject);


private:
    std::shared_ptr<Core::Interfaces::IRenderable> object_{nullptr};
};
