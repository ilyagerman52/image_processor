#include "sharpening.h"

Image Sharpening(const Image& image) {
    Image image2 = Image(image.GetWidth(), image.GetHeight());
    for (int x = 0; x != image.GetHeight(); ++x) {
        for (int y = 0; y != image.GetWidth(); ++y) {
            unsigned char rch = static_cast<unsigned char>(image.At(x, y).r_ * 255);
            unsigned char gch = static_cast<unsigned char>(image.At(x, y).g_ * 255);
            unsigned char bch = static_cast<unsigned char>(image.At(x, y).b_ * 255);

            int32_t r = rch;
            r *= 5;
            r -= static_cast<unsigned char>(image.At(x - 1, y).r_ * 255);
            r -= static_cast<unsigned char>(image.At(x + 1, y).r_ * 255);
            r -= static_cast<unsigned char>(image.At(x, y - 1).r_ * 255);
            r -= static_cast<unsigned char>(image.At(x, y + 1).r_ * 255);

            int32_t g = gch;
            g *= 5;
            g -= static_cast<unsigned char>(image.At(x - 1, y).g_ * 255);
            g -= static_cast<unsigned char>(image.At(x + 1, y).g_ * 255);
            g -= static_cast<unsigned char>(image.At(x, y - 1).g_ * 255);
            g -= static_cast<unsigned char>(image.At(x, y + 1).g_ * 255);

            int32_t b = bch;
            b *= 5;
            b -= static_cast<unsigned char>(image.At(x - 1, y).b_ * 255);
            b -= static_cast<unsigned char>(image.At(x + 1, y).b_ * 255);
            b -= static_cast<unsigned char>(image.At(x, y - 1).b_ * 255);
            b -= static_cast<unsigned char>(image.At(x, y + 1).b_ * 255);

            r = std::clamp(r, 0, 255);
            g = std::clamp(g, 0, 255);
            b = std::clamp(b, 0, 255);
            image2.SetColour(Colour(r / 255.0f, g / 255.0f, b / 255.0f), x, y);
        }
    }
    return image2;
}

Image FilterSharpening::Do(const Image& image, std::vector<std::string>) {
    return Sharpening(image);
}