#pragma once

#include <Interfaces/IModel.h>
#include <vector>

namespace Core::Interfaces
{
    class IRenderable;
}

namespace Core::ArchitectureCore
{
    class GeneratePointsModel;

    class GenerateAreaModel final : public Interfaces::IAreaModel
    {
    public:
        GenerateAreaModel(GeneratePointsModel* pointsModel, QObject* parent = nullptr);

        void StartGenerateArea(Core::Data::Point2D) override;
        void ProcessedGenerateArea(Core::Data::Point2D) override;
        void FinishGenerateArea(Core::Data::Point2D, Core::Data::UIDataInput) override;

        void Invoke(Core::Data::UIDataInput) override;

    private:
        GeneratePointsModel* pointsModel_{nullptr};
        Core::Data::Point2D startPoint_{0, 0};
        Core::Data::Point2D endPoint_{0, 0};
    };
} // namespace Core::ArchitectureCore
