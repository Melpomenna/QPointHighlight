#pragma once

#include <cstdint>
#include <string>

namespace Core::Data
{
    /**
     * @brief Structure to hold input data for UI elements.
     *
     * This structure contains information about the dimensions of the window,
     * the number of points to generate, and the radius of those points.
     */
    struct alignas(int64_t) UIDataInput final
    {
        int64_t windowWidth_{0}; ///< The width of the window.
        int64_t windowHeight_{0}; ///< The height of the window.
        int64_t generatePointsCount_{0}; ///< The number of points to generate.
        int64_t pointsRadius_{0}; ///< The radius of the points.
    };

    /**
     * @brief Represents a 2D point with x and y coordinates.
     */
    struct alignas(4) Point2D final
    {
        /**
         * @brief Constructs a Point2D with specified x and y coordinates.
         *
         * @param x The x-coordinate of the point.
         * @param y The y-coordinate of the point.
         */
        Point2D(float x, float y) : x_(x), y_(y)
        {
        }

        float x_{0}; ///< The x-coordinate of the point.
        float y_{0}; ///< The y-coordinate of the point.
    };

    /**
     * @brief Represents a color in RGBA format.
     */
    struct alignas(4) ColorRGBA final
    {
        /**
         * @brief Constructs a ColorRGBA with specified red, green, blue, and alpha values.
         *
         * @param r The red component of the color.
         * @param g The green component of the color.
         * @param b The blue component of the color.
         * @param a The alpha (transparency) component of the color.
         */
        ColorRGBA(int r, int g, int b, int a) : r_(r), g_(g), b_(b), a_(a)
        {
        }

        int r_{0}; ///< The red component of the color.
        int g_{0}; ///< The green component of the color.
        int b_{0}; ///< The blue component of the color.
        int a_{255}; ///< The alpha (transparency) component of the color.
    };

    /**
     * @brief Represents a circle in 2D space with a position and color.
     */
    struct alignas(4) Circle2D final
    {
        /**
         * @brief Constructs a Circle2D with specified position and color.
         *
         * @param x The x-coordinate of the circle's center.
         * @param y The y-coordinate of the circle's center.
         * @param r The red component of the circle's color (default is 0).
         * @param g The green component of the circle's color (default is 0).
         * @param b The blue component of the circle's color (default is 0).
         * @param a The alpha (transparency) component of the circle's color (default is 255).
         */
        Circle2D(float x, float y, int r = 0, int g = 0, int b = 0, int a = 255) : point2d_(x, y), color_(r, g, b, a)
        {
        }

        ColorRGBA color_{0, 0, 0, 1}; ///< The color of the circle.
        Point2D point2d_{0, 0}; ///< The position of the circle's center.
    };

    /**
     * @brief Represents a labeled circle in 2D space.
     *
     * This structure combines a label, a circle (with position and color),
     * and an optional radius. It is used to represent labeled circular
     * elements in a 2D UI or graphical context.
     */
    struct LabledCircle2D final
    {
        /**
         * @brief Constructs a LabledCircle2D with a label, position, and color.
         *
         * @param label The label associated with the circle.
         * @param x The x-coordinate of the circle's center.
         * @param y The y-coordinate of the circle's center.
         * @param r The red component of the circle's color (default is 0).
         * @param g The green component of the circle's color (default is 0).
         * @param b The blue component of the circle's color (default is 0).
         * @param a The alpha (transparency) component of the circle's color (default is 255).
         */
        LabledCircle2D(std::string label, float x, float y, int r = 0, int g = 0, int b = 0, int a = 255) :
            label_(label), circle_(x, y, r, g, b, a)
        {
        }

        /**
         * @brief Constructs a LabledCircle2D with a label, an existing circle, and a radius.
         *
         * @param label The label associated with the circle.
         * @param circle An existing Circle2D object to use for position and color.
         * @param radius The radius of the circle.
         */
        LabledCircle2D(std::string label, const Circle2D& circle, int64_t radius) :
            label_(label), circle_(circle), radius_(radius)
        {
        }

        std::string label_; ///< The label associated with the circle.
        Circle2D circle_; ///< The Circle2D object representing the circle's position and color.
        int64_t radius_{0}; ///< The radius of the circle.
    };

    /**
     * @brief Represents a captured area with a label and point count.
     */
    struct CapturedAreas final
    {
        /**
         * @brief Constructs a CapturedAreas object with a point count and label.
         *
         * @param pointsCount The number of points in the captured area.
         * @param label The label associated with the captured area.
         */
        CapturedAreas(int64_t pointsCount, std::string label) : label_(label), pointCount_(pointsCount)
        {
        }

        std::string label_; ///< The label associated with the captured area.
        int64_t pointCount_{0}; ///< The number of points in the captured area.
    };

} // namespace Core::Data
