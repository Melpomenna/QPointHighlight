#pragma once

#include <Interfaces/IModel.h>
#include <vector>

/**
 * @namespace Core::Interfaces
 * Contains interface definitions for core components.
 */
namespace Core::Interfaces
{
    /**
     * @class IRenderable
     * @brief Interface for renderable objects.
     */
    class IRenderable;
} // namespace Core::Interfaces

/**
 * @namespace Core::ArchitectureCore
 * Contains core architectural components.
 */
namespace Core::ArchitectureCore
{
    class GeneratePointsModel;

    /**
     * @class GenerateAreaModel
     * @brief Final class responsible for generating area models.
     *
     * This class implements the IAreaModel interface and provides functionality
     * for generating areas based on points and user input.
     */
    class GenerateAreaModel : public Interfaces::IAreaModel
    {
    public:
        /**
         * @brief Constructor for GenerateAreaModel.
         * @param pointsModel Pointer to the GeneratePointsModel instance.
         * @param parent Optional parent QObject.
         */
        GenerateAreaModel(GeneratePointsModel* pointsModel, QObject* parent = nullptr);

        /**
         * @brief Starts the area generation process.
         * @param point The starting point for area generation.
         */
        void StartGenerateArea(Core::Data::Point2D point) override;

        /**
         * @brief Processes the area generation.
         * @param point The current point being processed.
         */
        void ProcessedGenerateArea(Core::Data::Point2D point) override;

        /**
         * @brief Finishes the area generation process.
         * @param point The ending point for area generation.
         * @param input User input data for the UI.
         */
        void FinishGenerateArea(Core::Data::Point2D point, Core::Data::UIDataInput input) override;

        /**
         * @brief Invokes the area generation process with user input.
         * @param input User input data for the UI.
         */
        void Invoke(Core::Data::UIDataInput input) override;

    private:
        GeneratePointsModel* pointsModel_{nullptr}; /**< Pointer to the GeneratePointsModel instance. */
        Core::Data::Point2D startPoint_{0, 0}; /**< Starting point for area generation. */
        Core::Data::Point2D endPoint_{0, 0}; /**< Ending point for area generation. */
    };
} // namespace Core::ArchitectureCore
