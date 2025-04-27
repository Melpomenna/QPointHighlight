#pragma once

/**
 * @file IRenderable.h
 * @brief Defines the IRenderable interface for rendering operations.
 */

class QPaintEvent;
class QPaintDevice;

namespace Core::Interfaces
{
    /**
     * @class IRenderable
     * @brief An interface for objects that can be rendered.
     *
     * This interface provides a contract for objects that need to implement
     * custom rendering logic using a QPaintEvent and a QPaintDevice.
     */
    class IRenderable
    {
    public:
        /**
         * @brief Default constructor.
         */
        IRenderable() = default;

        /**
         * @brief Copy constructor.
         */
        IRenderable(const IRenderable&) = default;

        /**
         * @brief Copy assignment operator.
         * @return Reference to the assigned object.
         */
        IRenderable& operator=(const IRenderable&) = default;

        /**
         * @brief Move constructor.
         */
        IRenderable(IRenderable&&) noexcept = default;

        /**
         * @brief Move assignment operator.
         * @return Reference to the assigned object.
         */
        IRenderable& operator=(IRenderable&&) noexcept = default;

        /**
         * @brief Virtual destructor.
         */
        virtual ~IRenderable() = default;

        /**
         * @brief Draws the object using the provided paint event and device.
         *
         * @param event Pointer to the QPaintEvent containing painting details.
         * @param device Pointer to the QPaintDevice where the object will be drawn.
         */
        virtual void Draw(QPaintEvent* event, QPaintDevice* device) = 0;
    };
} // namespace Core::Interfaces
