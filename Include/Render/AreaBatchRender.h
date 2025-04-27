#pragma once

#include <Domain/UIData.h>
#include <Interfaces/IRenderable.h>
#include <QRect>

namespace Core::Render
{
    class AreaBatchRender final : public Interfaces::IRenderable
    {
    public:
        AreaBatchRender(const std::pmr::vector<Core::Data::Circle2D>& circles, QRect rect);

        void Draw(QPaintEvent* event, QPaintDevice* device) override;

    private:
        std::pmr::vector<Core::Data::Circle2D> circles_;
        QRect area_;
    };
} // namespace Core::Render
