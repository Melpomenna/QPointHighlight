#include <Render/BatchPointsRender.h>

#include <QPaintEvent>
#include <QPainter>

namespace Core::Render
{
    BatchPointsRender::BatchPointsRender(const std::pmr::vector<Data::Circle2D>& circles) : butch_(circles)
    {
    }

    void BatchPointsRender::Draw([[maybe_unused]] QPaintEvent*, QPaintDevice* device)
    {
        QPainter painter(device);
        QBrush brush;
        QPointF center;
        QColor color;
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        for (int64_t i = 0; i < butch_.size(); ++i)
        {
            auto pointColor = butch_[i].color_;
            color.setRed(pointColor.r_);
            color.setGreen(pointColor.g_);
            color.setBlue(pointColor.b_);
            color.setAlpha(pointColor.a_);
            brush.setColor(color);
            painter.setBrush(brush);
            center.setX(butch_[i].point2d_.x_);
            center.setY(butch_[i].point2d_.y_);
            painter.drawEllipse(center, butch_[i].radius_, butch_[i].radius_);
        }
    }

} // namespace Core::Render
