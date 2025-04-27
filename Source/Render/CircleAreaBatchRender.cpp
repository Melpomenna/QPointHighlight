#include <Render/CircleAreaBatchRender.h>

#include <QEvent>
#include <QPainter>

namespace Core::Render
{
    CircleAreaBatchRender::CircleAreaBatchRender(const std::pmr::vector<Data::LabledCircle2D>& areas,
                                                 const std::pmr::vector<Data::Circle2D>& circles) :
        circles_(circles), areas_(areas)
    {
    }

    void CircleAreaBatchRender::Draw(QPaintEvent* event, QPaintDevice* device)
    {
        QPainter painter(device);
        {
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
        }

        {
            QBrush brush;
            QPointF center;
            for (int64_t i = 0; i < areas_.size(); ++i)
            {
                brush.setColor(Qt::black);
                painter.setBrush(brush);
                center.setX(areas_[i].circle_.point2d_.x_);
                center.setY(areas_[i].circle_.point2d_.y_);
                painter.drawEllipse(center, areas_[i].radius_, areas_[i].radius_);
                painter.drawText(center, QString::fromStdString(areas_[i].label_));
            }
        }
    }
} // namespace Core::Render
