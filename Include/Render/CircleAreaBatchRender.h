#pragma once

#include <Domain/UIData.h>
#include <Interfaces/IRenderable.h>
#include <vector>

namespace Core::Render
{
    class CircleAreaBatchRender final : public Interfaces::IRenderable
    {
    public:
        CircleAreaBatchRender(const std::pmr::vector<Data::LabledCircle2D>&, const std::pmr::vector<Data::Circle2D>&);

        void Draw(QPaintEvent* event, QPaintDevice* device) override;

    private:
        std::pmr::vector<Data::Circle2D> circles_;
        std::pmr::vector<Data::LabledCircle2D> areas_;
    };
} // namespace Core::Render
