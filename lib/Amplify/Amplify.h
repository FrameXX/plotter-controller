#pragma once

#include <Arduino.h>
#include <Report.h>

template <typename Number>
Number amplify(Number value, Number minValue, Number maxValue, float exponent)
{
    const Number size = maxValue - minValue;

    const Number part = value - minValue;
    const float fraction = static_cast<float>(part) / static_cast<float>(size);
    const float amplifiedFraction = pow(fraction, exponent);
    const Number amplified = minValue + amplifiedFraction * size;
    return amplified;
}