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
    class GeneratePointsController : public Interfaces::IController
    {
    public:
        explicit GeneratePointsController(std::shared_ptr<Async::SharedContext> context, Interfaces::IModel* model,
                                          QObject* parent = nullptr);

    public slots:
        void OnControl(Core::Data::UIDataInput) override;

    private slots:
        void OnModelFinished(std::shared_ptr<Interfaces::IRenderable>);

    private:
        std::shared_ptr<Async::SharedContext> context_{nullptr};
        Interfaces::IModel* model_{nullptr};
    };
} // namespace Core::ArchitectureCore
