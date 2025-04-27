#pragma once

#include <Interfaces/IController.h>
#include <memory>

namespace Core::Async
{
    class SharedContext;
}

namespace Core::Interfaces
{
    class IModel;
}

namespace Core::ArchitectureCore
{
    /**
     * @class GeneratePointsController
     * @brief Controller responsible for generating points and managing interactions between the model and the UI.
     *
     * This class implements the IController interface and provides functionality to handle
     * UI input and process model outputs.
     */
    class GeneratePointsController : public Interfaces::IController
    {
    public:
        /**
         * @brief Constructs a GeneratePointsController.
         *
         * @param context Shared context for asynchronous operations.
         * @param model Pointer to the model used for generating points.
         * @param parent Optional parent QObject.
         */
        explicit GeneratePointsController(std::shared_ptr<Async::SharedContext> context, Interfaces::IModel* model,
                                          QObject* parent = nullptr);

    public slots:
        /**
         * @brief Slot to handle control input from the UI.
         *
         * @param input The UI data input to process.
         */
        void OnControl(Core::Data::UIDataInput) override;

    private slots:
        /**
         * @brief Slot triggered when the model finishes processing.
         *
         * @param renderable The renderable object produced by the model.
         */
        void OnModelFinished(std::shared_ptr<Interfaces::IRenderable>);

    private:
        std::shared_ptr<Async::SharedContext> context_{nullptr}; ///< Shared context for asynchronous operations.
        Interfaces::IModel* model_{nullptr}; ///< Pointer to the associated model.
    };
} // namespace Core::ArchitectureCore
