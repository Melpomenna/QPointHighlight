#pragma once

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

public slots:
    void UpdateView(std::shared_ptr<Core::Interfaces::IRenderable> renderObject);

 private:
    std::shared_ptr<Core::Interfaces::IRenderable> object_{nullptr};
};
