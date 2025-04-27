#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class RenderWidget final : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit RenderWidget(QWidget* parent = nullptr);
    ~RenderWidget() override = default;
};
