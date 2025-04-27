#pragma once

#include <cstdint>
#include <string>

namespace Core::Data
{
    /*
     * @brief UIDataInput structure to hold input data for UI elements.
     */
    struct alignas(int64_t) UIDataInput final
    {
        int64_t windowWidth_{0};
        int64_t windowHeight_{0};
        int64_t generatePointsCount_{0};
        int64_t pointsRadius_{0};
    };

    struct alignas(4) Point2D final
    {
        Point2D(float x, float y) : x_(x), y_(y)
        {
        }
        float x_{0};
        float y_{0};
    };

    struct alignas(4) ColorRGBA final
    {
        ColorRGBA(int r, int g, int b, int a) : r_(r), g_(g), b_(b), a_(a)
        {
        }
        int r_{0};
        int g_{0};
        int b_{0};
        int a_{255};
    };

    struct alignas(4) Circle2D final
    {
        Circle2D(float x, float y, int r = 0, int g = 0, int b = 0, int a = 255) : point2d_(x, y), color_(r, g, b, a)
        {
        }
        ColorRGBA color_{0, 0, 0, 1};
        Point2D point2d_{0, 0};
    };

    struct LabledCircle2D final
    {
        LabledCircle2D(std::string label, float x, float y, int r = 0, int g = 0, int b = 0, int a = 255) :
            label_(label), circle_(x, y, r, g, b, a)
        {
        }

        LabledCircle2D(std::string label, const Circle2D& circle, int64_t radius) :
            label_(label), circle_(circle), radius_(radius)
        {
        }
        std::string label_;
        Circle2D circle_;
        int64_t radius_{0};
    };

    struct CapturedAreas final
    {
        CapturedAreas(int64_t pointsCount, std::string label) : label_(label), pointCount_(pointsCount)
        {
        }
        std::string label_;
        int64_t pointCount_{0};
    };

} // namespace Core::Data
