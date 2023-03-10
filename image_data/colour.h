#pragma once

#include <tuple>

class Colour {
public:
    Colour();
    Colour(float r, float g, float b);
    Colour(const Colour& other_colour);
    ~Colour();

    bool operator==(const Colour& other) const = default;

    float r_ = 0;
    float g_ = 0;
    float b_ = 0;
};
