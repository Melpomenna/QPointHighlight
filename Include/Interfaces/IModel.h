#pragma once

#include <Domain/UIData.h>
#include <QObject>

namespace Core::Interfaces
{
    class IRenderable;
}

namespace Core::Async
{
    class SharedContext;
}

namespace Core::Interfaces
{
    class IModel : public QObject
    {
        Q_OBJECT;

    public:
        explicit IModel(QObject* parent = nullptr) : QObject(parent)
        {
        }

    public slots:
        virtual void Invoke(Core::Data::UIDataInput, std::shared_ptr<Async::SharedContext> context) = 0;

    signals:
        void OnFinished(std::shared_ptr<Core::Interfaces::IRenderable>);
    };

    class IAreaModel : public QObject
    {
        Q_OBJECT;

    public:
        explicit IAreaModel(QObject* parent = nullptr) : QObject(parent)
        {
        }

        virtual void Invoke(Core::Data::UIDataInput) = 0;

    public slots:
        virtual void StartGenerateArea(Core::Data::Point2D) = 0;
        virtual void ProcessedGenerateArea(Core::Data::Point2D) = 0;
        virtual void FinishGenerateArea(Core::Data::Point2D, Core::Data::UIDataInput) = 0;

    signals:
        void OnCreatePart(std::shared_ptr<Core::Interfaces::IRenderable>);
        void OnFinished(std::shared_ptr<Core::Interfaces::IRenderable>);
        void OnFinishedRecalcAreaCount(std::pmr::vector<Core::Data::CapturedAreas>);
    };
} // namespace Core::Interfaces
