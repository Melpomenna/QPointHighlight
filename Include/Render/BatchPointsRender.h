#pragma once

#include <Domain/UIData.h>
#include <Interfaces/IRenderable.h>
#include <QColor>
#include <QList>
#include <QRect>
#include <vector>

namespace Core::Render
{
    /**
     * @class BatchPointsRender
     * @brief A class responsible for rendering a batch of 2D circles.
     *
     * This class implements the IRenderable interface and provides functionality
     * to render a collection of 2D circles using a QPaintDevice.
     */
    class BatchPointsRender final : public Interfaces::IRenderable
    {
    public:
        /**
         * @brief Constructs a BatchPointsRender object.
         *
         * @param circles A vector of Circle2D objects to be rendered.
         */
        explicit BatchPointsRender(const std::pmr::vector<Data::Circle2D>& circles);

        /**
         * @brief Default destructor.
         */
        ~BatchPointsRender() = default;

        /**
         * @brief Draws the batch of circles on the specified device.
         *
         * @param event The paint event containing information about the drawing context.
         * @param device The QPaintDevice on which the circles will be rendered.
         */
        void Draw(QPaintEvent* event, QPaintDevice* device) override;

    private:
        /**
         * @brief A vector containing the batch of Circle2D objects to be rendered.
         */
        std::pmr::vector<Data::Circle2D> butch_;
    };
} // namespace Core::Render
