#include "grayscale.h"

namespace {
Colour ToGray(const Colour& colour) {
    unsigned char r = static_cast<unsigned char>(colour.r_ * 255);
    unsigned char g = static_cast<unsigned char>(colour.g_ * 255);
    unsigned char b = static_cast<unsigned char>(colour.b_ * 255);
    float res = r * 0.299 + g * 0.587 + b * 0.114;
    Colour colour2;
    colour2.r_ = (res / 255);
    colour2.g_ = (res / 255);
    colour2.b_ = (res / 255);
    return colour2;
}
}  // namespace

Image Grayscale(const Image& image) {
    int width = image.GetWidth();
    int height = image.GetHeight();
    Image image2 = Image(width, height);
    for (int x = 0; x != height; ++x) {
        for (int y = 0; y != width; ++y) {
            image2.SetColour(ToGray(image.GetColour(x, y)), x, y);
        }
    }
    return image2;
}

Image FilterGrayscale::Do(const Image& image, std::vector<std::string>) {
    return Grayscale(image);
}