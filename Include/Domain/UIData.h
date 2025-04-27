#pragma once

namespace Core::Data
{
    /*
     * @brief UIDataInput structure to hold input data for UI elements.
    */
    struct alignas(sizeof(void*)) UIDataInput
    {
        int generatePointsCount_{0};
        int pointsRadius_{0};
    };
}
