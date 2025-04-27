#pragma once

#include <Interfaces/IModel.h>
#include <memory_resource>
#include <vector>

namespace Core::ArchitectureCore
{
    class GeneratePointsModel final : public Interfaces::IModel
    {
    public:
        explicit GeneratePointsModel(QObject* parent = nullptr);

        void Invoke(Core::Data::UIDataInput, std::shared_ptr<Async::SharedContext> context) override;

        _NODISCARD const std::pmr::vector<Data::Circle2D> GetData() const& noexcept;

    private:
        std::pmr::unsynchronized_pool_resource memoryResources_;
        std::pmr::vector<Data::Circle2D> circles_;
    };
} // namespace Core::ArchitectureCore
