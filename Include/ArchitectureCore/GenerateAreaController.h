#pragma once

#include <Interfaces/IController.h>
#include <memory>

namespace Core::Async
{
    class SharedContext;
}

namespace Core::Interfaces
{
    class IAreaModel;
}

namespace Core::ArchitectureCore
{
    /**
     * @class GenerateAreaController
     * @brief Controller responsible for managing area generation processes.
     *
     * This class implements the IAreaController interface and provides
     * functionality to control the area generation process, including
     * starting, controlling, and finishing the process. It also handles
     * signals emitted by the model during the process.
     */
    class GenerateAreaController : public Interfaces::IAreaController
    {
    public:
        /**
         * @brief Constructor for GenerateAreaController.
         *
         * @param context Shared context for asynchronous operations.
         * @param model Pointer to the area model.
         * @param parent Optional parent QObject.
         */
        explicit GenerateAreaController(std::shared_ptr<Async::SharedContext> context, Interfaces::IAreaModel* model,
                                        QObject* parent = nullptr);

        /**
         * @brief Called to start controlling the area generation process.
         *
         * @param point The starting point for the control process.
         */
        void OnStartControl(Core::Data::Point2D point);

        /**
         * @brief Called to control the area generation process.
         *
         * @param point The current point being processed.
         */
        void OnControl(Core::Data::Point2D point);

        /**
         * @brief Called to finish the area generation process.
         *
         * @param point The final point of the process.
         * @param input Additional input data for the UI.
         */
        void OnFinishedControl(Core::Data::Point2D point, Core::Data::UIDataInput input);

    private slots:
        /**
         * @brief Slot triggered when the model finishes processing.
         *
         * @param renderable The renderable object produced by the model.
         */
        void OnModelFinished(std::shared_ptr<Interfaces::IRenderable> renderable);

        /**
         * @brief Slot triggered when the model finishes processing a part.
         *
         * @param renderable The renderable part produced by the model.
         */
        void OnModelFinishedPart(std::shared_ptr<Interfaces::IRenderable> renderable);

        /**
         * @brief Slot triggered when the model finishes recalculating the area.
         *
         * @param capturedAreas The recalculated captured areas.
         */
        void OnModelFinishedRecalcArea(std::pmr::vector<Core::Data::CapturedAreas> capturedAreas);

    private:
        std::shared_ptr<Async::SharedContext> context_{nullptr}; ///< Shared context for asynchronous operations.
        Interfaces::IAreaModel* model_{nullptr}; ///< Pointer to the area model.
    };
} // namespace Core::ArchitectureCore
