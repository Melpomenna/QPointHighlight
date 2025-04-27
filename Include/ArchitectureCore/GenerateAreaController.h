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
    class GenerateAreaController : public Interfaces::IAreaController
    {
    public:
        explicit GenerateAreaController(std::shared_ptr<Async::SharedContext> context, Interfaces::IAreaModel* model,
                                        QObject* parent = nullptr);

        void OnStartControl(Core::Data::Point2D);
        void OnControl(Core::Data::Point2D);
        void OnFinishedControl(Core::Data::Point2D, Core::Data::UIDataInput);

    private slots:
        void OnModelFinished(std::shared_ptr<Interfaces::IRenderable>);
        void OnModelFinishedPart(std::shared_ptr<Interfaces::IRenderable>);
        void OnModelFinishedRecalcArea(std::pmr::vector<Core::Data::CapturedAreas>);

    private:
        std::shared_ptr<Async::SharedContext> context_{nullptr};
        Interfaces::IAreaModel* model_{nullptr};
    };
} // namespace Core::ArchitectureCore
