#include <ArchitectureCore/GenerateAreaController.h>
#include <Interfaces/IModel.h>

#include <Async/Context.h>

namespace Core::ArchitectureCore
{
    GenerateAreaController::GenerateAreaController(std::shared_ptr<Async::SharedContext> context,
                                                   Interfaces::IAreaModel* model, QObject* parent) :
        IAreaController(parent), context_(context), model_(model)
    {
        connect(this, &GenerateAreaController::OnStartModel, model, &Interfaces::IAreaModel::StartGenerateArea);
        connect(this, &GenerateAreaController::OnProcessedModel, model, &Interfaces::IAreaModel::ProcessedGenerateArea);
        connect(this, &GenerateAreaController::OnFinishedModel, model, &Interfaces::IAreaModel::FinishGenerateArea);
        connect(model_, &Interfaces::IAreaModel::OnCreatePart, this, &GenerateAreaController::OnModelFinishedPart);
        connect(model_, &Interfaces::IAreaModel::OnFinished, this, &GenerateAreaController::OnModelFinished);
        connect(model_, &Interfaces::IAreaModel::OnFinishedRecalcAreaCount, this,
                &GenerateAreaController::OnModelFinishedRecalcArea);
    }

    void GenerateAreaController::OnStartControl(Core::Data::Point2D startPoint)
    {
        if (context_->IsRunning())
            return;
        emit OnStartModel(startPoint);
    }

    void GenerateAreaController::OnControl(Core::Data::Point2D endPoint)
    {
        if (context_->IsRunning())
            return;
        emit OnProcessedModel(endPoint);
    }

    void GenerateAreaController::OnFinishedControl(Core::Data::Point2D endPoint, Core::Data::UIDataInput uiData)
    {
        if (context_->IsRunning())
            return;
        emit OnFinishedModel(endPoint, uiData);
    }

    void GenerateAreaController::OnModelFinished(std::shared_ptr<Interfaces::IRenderable> renderObject)
    {
        if (context_->IsRunning())
            return;
        emit OnFinished(renderObject);
    }

    void GenerateAreaController::OnModelFinishedPart(std::shared_ptr<Interfaces::IRenderable> renderObject)
    {
        if (context_->IsRunning())
            return;
        emit OnFinishedPart(renderObject);
    }

    void GenerateAreaController::OnModelFinishedRecalcArea(std::pmr::vector<Core::Data::CapturedAreas> areas)
    {
        if (context_->IsRunning())
            return;
        emit OnFinishedRecalcArea(areas);
    }

} // namespace Core::ArchitectureCore
