#include "negative.h"

namespace {
Colour Reverse(const Colour& colour) {
    float r = 1 - colour.r_;
    float g = 1 - colour.g_;
    float b = 1 - colour.b_;
    return Colour(r, g, b);
}
}  // namespace

Image Negative(const Image& image) {
    int width = image.GetWidth();
    int height = image.GetHeight();
    Image image2 = Image(width, height);
    for (int x = 0; x != height; ++x) {
        for (int y = 0; y != width; ++y) {
            image2.SetColour(Reverse(image.GetColour(x, y)), x, y);
        }
    }
    return image2;
}

Image FilterNegative::Do(const Image& image, std::vector<std::string>) {
    return Negative(image);
}