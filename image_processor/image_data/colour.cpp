#include "colour.h"

Colour::Colour() = default;
Colour::Colour(float r, float g, float b) : r_(r), g_(g), b_(b){};
Colour::Colour(const Colour& other_colour) : r_(other_colour.r_), g_(other_colour.g_), b_(other_colour.b_){};
Colour::~Colour() = default;



