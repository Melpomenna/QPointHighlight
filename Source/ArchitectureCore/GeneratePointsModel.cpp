#include <ArchitectureCore/GeneratePointsModel.h>

#include <Async/Context.h>
#include <Render/BatchPointsRender.h>
#include <chrono>
#include <random>

namespace Core::ArchitectureCore
{
    GeneratePointsModel::GeneratePointsModel(QObject* parent) :
        IModel(parent),
        memoryResources_(std::pmr::pool_options({std::hardware_constructive_interference_size * sizeof(Data::Circle2D),
                                                 std::hardware_constructive_interference_size}),
                         std::pmr::get_default_resource()),
        circles_(decltype(circles_)::allocator_type(&memoryResources_))
    {
    }

    void GeneratePointsModel::Invoke(Core::Data::UIDataInput uiData, std::shared_ptr<Async::SharedContext> context)
    {
        if (!context->IsRunning())
            return;

        circles_.clear();
        circles_.reserve(uiData.generatePointsCount_);
        float x = 0, y = 0;

        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_real_distribution<float> positionXDistribution(0, uiData.windowWidth_);
        std::uniform_real_distribution<float> positionYDistribution(0, uiData.windowHeight_);
        std::uniform_int_distribution colorDistribution(0, 255);

        for (int64_t i = 0; i < uiData.generatePointsCount_ && context->IsRunning(); ++i)
        {
            x = positionXDistribution(generator);
            y = positionYDistribution(generator);
            circles_.emplace_back(x, y, colorDistribution(generator), colorDistribution(generator),
                                  colorDistribution(generator));
        }

        if (context->IsRunning())
        {
            std::shared_ptr<Interfaces::IRenderable> renderObject =
                std::make_shared<Render::BatchPointsRender>(circles_);
            emit OnFinished(renderObject);
        }
    }

    _NODISCARD const std::pmr::vector<Data::Circle2D> GeneratePointsModel::GetData() const& noexcept
    {
        return circles_;
    }

} // namespace Core::ArchitectureCore
