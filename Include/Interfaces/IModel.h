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
    /**
     * @brief Interface for a model that can be invoked with input data and a shared context.
     */
    class IModel : public QObject
    {
        Q_OBJECT;

    public:
        /**
         * @brief Constructs an IModel instance.
         * @param parent The parent QObject, default is nullptr.
         */
        explicit IModel(QObject* parent = nullptr) : QObject(parent)
        {
        }

    public slots:
        /**
         * @brief Invokes the model with the given input data and shared context.
         * @param input The input data for the model.
         * @param context A shared context for managing the state of the operation.
         */
        virtual void Invoke(Core::Data::UIDataInput input, std::shared_ptr<Async::SharedContext> context) = 0;

    signals:
        /**
         * @brief Signal emitted when the operation is finished.
         * @param renderable A shared pointer to the renderable result.
         */
        void OnFinished(std::shared_ptr<Core::Interfaces::IRenderable> renderable);
    };

    /**
     * @brief Interface for a model that handles area-related operations.
     */
    class IAreaModel : public QObject
    {
        Q_OBJECT;

    public:
        /**
         * @brief Constructs an IAreaModel instance.
         * @param parent The parent QObject, default is nullptr.
         */
        explicit IAreaModel(QObject* parent = nullptr) : QObject(parent)
        {
        }

        /**
         * @brief Invokes the area model with the given input data.
         * @param input The input data for the area model.
         */
        virtual void Invoke(Core::Data::UIDataInput input) = 0;

    public slots:
        /**
         * @brief Starts generating an area based on the given point.
         * @param point The point to start generating the area.
         */
        virtual void StartGenerateArea(Core::Data::Point2D point) = 0;

        /**
         * @brief Processes the generation of an area based on the given point.
         * @param point The point being processed for area generation.
         */
        virtual void ProcessedGenerateArea(Core::Data::Point2D point) = 0;

        /**
         * @brief Finishes generating an area based on the given point and input data.
         * @param point The point where the area generation is finished.
         * @param input The input data used for area generation.
         */
        virtual void FinishGenerateArea(Core::Data::Point2D point, Core::Data::UIDataInput input) = 0;

    signals:
        /**
         * @brief Signal emitted when a part of the area is created.
         * @param renderable A shared pointer to the renderable part.
         */
        void OnCreatePart(std::shared_ptr<Core::Interfaces::IRenderable> renderable);

        /**
         * @brief Signal emitted when the area generation is finished.
         * @param renderable A shared pointer to the renderable result.
         */
        void OnFinished(std::shared_ptr<Core::Interfaces::IRenderable> renderable);

        /**
         * @brief Signal emitted when the recalculation of area counts is finished.
         * @param capturedAreas A vector of captured areas.
         */
        void OnFinishedRecalcAreaCount(std::pmr::vector<Core::Data::CapturedAreas> capturedAreas);
    };
} // namespace Core::Interfaces
