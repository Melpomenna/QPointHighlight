#include <ArchitectureCore/GenerateAreaModel.h>

#include <ArchitectureCore/GeneratePointsModel.h>
#include <QRect>
#include <QThreadPool>
#include <Render/AreaBatchRender.h>
#include <Render/CircleAreaBatchRender.h>

namespace Core::ArchitectureCore
{
    namespace
    {
        class GenerateAreaTask final : public QRunnable
        {
        public:
            GenerateAreaTask(GenerateAreaModel* model, Core::Data::UIDataInput uiData) : model_(model), uiData_(uiData)
            {
            }

            void run() override
            {
                model_->Invoke(uiData_);
            }

        private:
            GenerateAreaModel* model_{nullptr};
            Core::Data::UIDataInput uiData_;
        };
    } // namespace


    GenerateAreaModel::GenerateAreaModel(GeneratePointsModel* pointsModel, QObject* parent) :
        IAreaModel(parent), pointsModel_(pointsModel)
    {
    }

    void GenerateAreaModel::StartGenerateArea(Core::Data::Point2D startPoint)
    {
        if (pointsModel_->GetData().empty())
        {
            emit OnFinished(nullptr);
            return;
        }
        startPoint_ = startPoint;
    }

    void GenerateAreaModel::ProcessedGenerateArea(Core::Data::Point2D endPoint)
    {
        if (pointsModel_->GetData().empty())
        {
            emit OnFinished(nullptr);
            return;
        }
        QRect rect;
        rect.setX(startPoint_.x_);
        rect.setY(startPoint_.y_);
        rect.setWidth(endPoint.x_ - startPoint_.x_);
        rect.setHeight(endPoint.y_ - startPoint_.y_);

        emit OnCreatePart(std::make_shared<Render::AreaBatchRender>(pointsModel_->GetData(), rect));
    }

    void GenerateAreaModel::FinishGenerateArea(Core::Data::Point2D endPoint, Core::Data::UIDataInput uiData)
    {
        if (pointsModel_->GetData().empty())
        {
            emit OnFinished(nullptr);
            return;
        }

        endPoint_ = endPoint;

        QRunnable* task = new GenerateAreaTask(this, uiData);
        QThreadPool::globalInstance()->start(task);
    }

    void GenerateAreaModel::Invoke(Core::Data::UIDataInput uiData)
    {
        std::pmr::vector<Data::LabledCircle2D> areas;
        std::pmr::vector<Data::CapturedAreas> capturedAreas{};

        QRectF rect;
        rect.setX(startPoint_.x_);
        rect.setY(startPoint_.y_);
        rect.setWidth(endPoint_.x_ - startPoint_.x_);
        rect.setHeight(endPoint_.y_ - startPoint_.y_);

        const auto& data = pointsModel_->GetData();

        for (int64_t i = 0; i < data.size(); ++i)
        {
            if (rect.contains(data[i].point2d_.x_, data[i].point2d_.y_))
                areas.push_back({QString::asprintf("Area:%llu", i).toStdString(), data[i], uiData.pointsRadius_});
        }

        for (int64_t i = 0; i < areas.size(); ++i)
        {
            int64_t count = 1;
            for (int64_t j = 0; j < areas.size(); ++j)
            {
                if (i != j)
                {
                    double dx = (areas[j].circle_.point2d_.x_ - areas[i].circle_.point2d_.x_);
                    double dy = (areas[j].circle_.point2d_.y_ - areas[i].circle_.point2d_.y_);
                    dx *= dx;
                    dy *= dy;
                    double distanceSquared = dx + dy;
                    count += distanceSquared <= (uiData.pointsRadius_ * uiData.pointsRadius_);
                }
            }
            capturedAreas.emplace_back(count, areas[i].label_);
        }
        emit OnFinished(std::make_shared<Render::CircleAreaBatchRender>(areas, data));
        emit OnFinishedRecalcAreaCount(capturedAreas);
    }

} // namespace Core::ArchitectureCore
