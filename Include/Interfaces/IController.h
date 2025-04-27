#pragma once

#include <Domain/UIData.h>
#include <QObject>

namespace Core::Interfaces
{
    class IRenderable;

    /**
     * @brief Interface for a generic controller.
     *
     * This interface defines the basic structure for a controller that processes UI data input
     * and emits a signal when processing is finished.
     */
    class IController : public QObject
    {
        Q_OBJECT
    public:
        /**
         * @brief Constructor for IController.
         * @param parent The parent QObject.
         */
        explicit IController(QObject* parent = nullptr) : QObject(parent)
        {
        }

        /**
         * @brief Virtual destructor for IController.
         */
        ~IController() override = default;

    signals:
        /**
         * @brief Signal emitted when processing is finished.
         * @param renderable A shared pointer to the renderable object.
         */
        void OnFinished(std::shared_ptr<IRenderable>);

    public slots:
        /**
         * @brief Slot to handle control logic.
         * @param input The UI data input to process.
         */
        virtual void OnControl(Core::Data::UIDataInput input) = 0;
    };

    /**
     * @brief Interface for an area-specific controller.
     *
     * This interface extends QObject and provides additional signals and slots
     * for handling area-specific control logic.
     */
    class IAreaController : public QObject
    {
        Q_OBJECT
    public:
        explicit IAreaController(QObject* parent = nullptr) : QObject(parent)
        {
        }

        /**
         * @brief Virtual destructor for IAreaController.
         */
        ~IAreaController() override = default;

    signals:
        /**
         * @brief Signal emitted when processing is finished.
         * @param renderable A shared pointer to the renderable object.
         */
        void OnFinished(std::shared_ptr<IRenderable>);

        /**
         * @brief Signal emitted when a part of the processing is finished.
         * @param renderable A shared pointer to the renderable object.
         */
        void OnFinishedPart(std::shared_ptr<IRenderable>);

        /**
         * @brief Signal emitted when a model starts processing.
         * @param point The starting point of the model.
         */
        void OnStartModel(Core::Data::Point2D point);

        /**
         * @brief Signal emitted when a model is processed.
         * @param point The processed point of the model.
         */
        void OnProcessedModel(Core::Data::Point2D point);

        /**
         * @brief Signal emitted when a model finishes processing.
         * @param point The finished point of the model.
         * @param input The UI data input associated with the model.
         */
        void OnFinishedModel(Core::Data::Point2D point, Core::Data::UIDataInput input);

        /**
         * @brief Signal emitted when recalculating an area is finished.
         * @param areas A vector of captured areas.
         */
        void OnFinishedRecalcArea(std::pmr::vector<Core::Data::CapturedAreas> areas);

    public slots:
        /**
         * @brief Slot to handle the start of control logic.
         * @param point The starting point for control.
         */
        virtual void OnStartControl(Core::Data::Point2D point) = 0;

        /**
         * @brief Slot to handle control logic.
         * @param point The point to process.
         */
        virtual void OnControl(Core::Data::Point2D point) = 0;

        /**
         * @brief Slot to handle the end of control logic.
         * @param point The finished point of control.
         * @param input The UI data input associated with the control.
         */
        virtual void OnFinishedControl(Core::Data::Point2D point, Core::Data::UIDataInput input) = 0;
    };
} // namespace Core::Interfaces
