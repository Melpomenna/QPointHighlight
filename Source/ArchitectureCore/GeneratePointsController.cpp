#include <ArchitectureCore/GeneratePointsController.h>

#include <QThreadPool.h>

#include <Async/Context.h>
#include <Interfaces/IModel.h>

namespace Core::ArchitectureCore
{

    namespace
    {
        class GeneratePointsControllerTask final : public QRunnable
        {
        public:
            GeneratePointsControllerTask(Interfaces::IModel* model, std::shared_ptr<Async::SharedContext> context,
                                         Data::UIDataInput uiData) : model_(model), context_(context), uiData_(uiData)
            {
            }

            void run() override
            {
                model_->Invoke(uiData_, context_);
            }

        private:
            Interfaces::IModel* model_{nullptr};
            std::shared_ptr<Async::SharedContext> context_{nullptr};
            Data::UIDataInput uiData_;
        };
    } // namespace

    GeneratePointsController::GeneratePointsController(std::shared_ptr<Async::SharedContext> context,
                                                       Interfaces::IModel* model, QObject* parent) :
        IController(parent), context_(context), model_(model)
    {
        connect(model, &Interfaces::IModel::OnFinished, this, &GeneratePointsController::OnModelFinished);
    }

    void GeneratePointsController::OnModelFinished(std::shared_ptr<Interfaces::IRenderable> renderObject)
    {
        emit OnFinished(renderObject);
    }

    void GeneratePointsController::OnControl(Core::Data::UIDataInput data)
    {
        if (context_->IsRunning())
            context_->TryCancel();
        context_->SetState(Async::State::Running);
        QRunnable* task = new GeneratePointsControllerTask(model_, context_, data);
        QThreadPool::globalInstance()->start(task);
    }

} // namespace Core::ArchitectureCore
