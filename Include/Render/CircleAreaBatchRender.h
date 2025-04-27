#pragma once

#include <Domain/UIData.h>
#include <Interfaces/IRenderable.h>
#include <vector>

namespace Core::Render
{
    /**
     * @class CircleAreaBatchRender
     * @brief A class responsible for rendering batches of circle areas and labeled circles.
     *
     * This class implements the IRenderable interface and provides functionality
     * to render a collection of circles and labeled circles using a QPaintDevice.
     */
    class CircleAreaBatchRender final : public Interfaces::IRenderable
    {
    public:
        /**
         * @brief Constructs a CircleAreaBatchRender object.
         *
         * @param areas A vector of labeled circles to be rendered.
         * @param circles A vector of circles to be rendered.
         */
        CircleAreaBatchRender(const std::pmr::vector<Data::LabledCircle2D>& areas,
                              const std::pmr::vector<Data::Circle2D>& circles);

        /**
         * @brief Draws the circles and labeled circles on the provided QPaintDevice.
         *
         * @param event The QPaintEvent containing information about the paint event.
         * @param device The QPaintDevice on which the rendering will be performed.
         */
        void Draw(QPaintEvent* event, QPaintDevice* device) override;

    private:
        std::pmr::vector<Data::Circle2D> circles_; ///< A vector containing the circles to be rendered.
        std::pmr::vector<Data::LabledCircle2D> areas_; ///< A vector containing the labeled circles to be rendered.
    };
} // namespace Core::Render
