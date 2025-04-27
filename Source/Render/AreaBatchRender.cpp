#include <Render/AreaBatchRender.h>

#include <QPaintEvent>
#include <QPainter>

namespace Core::Render
{
    AreaBatchRender::AreaBatchRender(const std::pmr::vector<Core::Data::Circle2D>& circles, QRect rect) :
        circles_(circles), area_(rect)
    {
    }

    void AreaBatchRender::Draw(QPaintEvent* event, QPaintDevice* device)
    {
        QPainter painter(device);
        QBrush brush;
        QPointF center;
        QColor color;
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        for (int64_t i = 0; i < circles_.size(); ++i)
        {
            auto pointColor = circles_[i].color_;
            color.setRed(pointColor.r_);
            color.setGreen(pointColor.g_);
            color.setBlue(pointColor.b_);
            color.setAlpha(pointColor.a_);
            brush.setColor(color);
            painter.setBrush(brush);
            center.setX(circles_[i].point2d_.x_);
            center.setY(circles_[i].point2d_.y_);
            painter.drawEllipse(center, DEFAULT_AREA_RADIUS, DEFAULT_AREA_RADIUS);
        }
        QBrush areaBrush;
        areaBrush.setColor(Qt::black);
        painter.setBrush(areaBrush);
        painter.drawRect(area_);
    }
} // namespace Core::Render
