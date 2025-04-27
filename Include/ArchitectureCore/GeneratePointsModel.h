#pragma once

#include <Interfaces/IModel.h>
#include <memory_resource>
#include <vector>

namespace Core::ArchitectureCore
{
    /**
     * @class GeneratePointsModel
     * @brief A model class responsible for generating points and managing related data.
     *
     * This class implements the IModel interface and provides functionality to invoke
     * operations and retrieve generated circle data. It uses a polymorphic memory resource
     * for efficient memory management.
     */
    class GeneratePointsModel : public Interfaces::IModel
    {
    public:
        /**
         * @brief Constructs a GeneratePointsModel object.
         *
         * @param parent A pointer to the parent QObject, default is nullptr.
         */
        explicit GeneratePointsModel(QObject* parent = nullptr);

        /**
         * @brief Invokes the model operation with the given input and shared context.
         *
         * @param input The UI data input required for the operation.
         * @param context A shared pointer to the asynchronous shared context.
         */
        void Invoke(Core::Data::UIDataInput input, std::shared_ptr<Async::SharedContext> context) override;

        /**
         * @brief Retrieves the generated circle data.
         *
         * @return A constant reference to a polymorphic memory resource vector of Circle2D objects.
         */
        _NODISCARD const std::pmr::vector<Data::Circle2D>& GetData() const noexcept;

    private:
        std::pmr::unsynchronized_pool_resource memoryResources_; ///< Memory resource for efficient allocation.
        std::pmr::vector<Data::Circle2D> circles_; ///< Vector storing generated circle data.
    };
} // namespace Core::ArchitectureCore
