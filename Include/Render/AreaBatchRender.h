#pragma once

#include <Domain/UIData.h>
#include <Interfaces/IRenderable.h>
#include <QRect>

namespace Core::Render
{
    /**
     * @class AreaBatchRender
     * @brief A class responsible for rendering a batch of circular areas within a specified rectangular region.
     *
     * This class implements the IRenderable interface and provides functionality to render
     * a collection of 2D circles within a defined area using Qt's painting framework.
     */
    class AreaBatchRender final : public Interfaces::IRenderable
    {
    public:
        /**
         * @brief Constructs an AreaBatchRender object.
         *
         * @param circles A vector of 2D circles to be rendered.
         * @param rect The rectangular area within which the circles will be rendered.
         */
        AreaBatchRender(const std::pmr::vector<Core::Data::Circle2D>& circles, QRect rect);

        /**
         * @brief Renders the batch of circles onto the specified device.
         *
         * @param event The paint event containing information about the painting operation.
         * @param device The device on which the rendering will be performed.
         */
        void Draw(QPaintEvent* event, QPaintDevice* device) override;

    private:
        std::pmr::vector<Core::Data::Circle2D> circles_; ///< The collection of circles to be rendered.
        QRect area_; ///< The rectangular area within which the circles are rendered.
    };
} // namespace Core::Render
