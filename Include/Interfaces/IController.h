#pragma once

#include <QObject>

#include <Domain/UIData.h>

namespace Core::Interfaces
{
    class IRenderable;

    class IController : public QObject
    {
        Q_OBJECT
    public:
        explicit IController(QObject* parent = nullptr) : QObject(parent)
        {
        }

        ~IController() override = default;


    signals:
        void OnFinished(std::shared_ptr<IRenderable>);

    public slots:
        virtual void OnControl(Core::Data::UIDataInput) = 0;
    };

    class IAreaController : public QObject
    {
        Q_OBJECT
    public:
        explicit IAreaController(QObject* parent = nullptr) : QObject(parent)
        {
        }

        ~IAreaController() override = default;


    signals:
        void OnFinished(std::shared_ptr<IRenderable>);
        void OnFinishedPart(std::shared_ptr<IRenderable>);
        void OnStartModel(Core::Data::Point2D);
        void OnProcessedModel(Core::Data::Point2D);
        void OnFinishedModel(Core::Data::Point2D, Core::Data::UIDataInput);
        void OnFinishedRecalcArea(std::pmr::vector<Core::Data::CapturedAreas>);

    public slots:
        virtual void OnStartControl(Core::Data::Point2D) = 0;
        virtual void OnControl(Core::Data::Point2D) = 0;
        virtual void OnFinishedControl(Core::Data::Point2D, Core::Data::UIDataInput) = 0;
    };
} // namespace Core::Interfaces
