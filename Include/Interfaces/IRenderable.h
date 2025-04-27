#pragma once

class QPaintEvent;
class QPaintDevice;

namespace Core::Interfaces
{
    class IRenderable
    {
    public:
        IRenderable() = default;

        IRenderable(const IRenderable&) = default;
        IRenderable& operator=(const IRenderable&) = default;
        IRenderable(IRenderable&&) noexcept = default;
        IRenderable& operator=(IRenderable&&) noexcept = default;

        virtual ~IRenderable() = default;

        virtual void Draw(QPaintEvent* event, QPaintDevice* device) = 0;
    };
} // namespace Core::Interfaces
