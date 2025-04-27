#pragma once

#include <Domain/UIData.h>
#include <Interfaces/IRenderable.h>
#include <QColor>
#include <QList>
#include <QRect>
#include <vector>

namespace Core::Render
{
    class BatchPointsRender final : public Interfaces::IRenderable
    {
    public:
        explicit BatchPointsRender(const std::pmr::vector<Data::Circle2D>& circles);
        ~BatchPointsRender() = default;

        void Draw(QPaintEvent* event, QPaintDevice* device) override;

    private:
        std::pmr::vector<Data::Circle2D> butch_;
    };
} // namespace Core::Render
