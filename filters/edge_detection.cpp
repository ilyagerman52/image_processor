#include "edge_detection.h"
#include "grayscale.h"

Image EdgeDetection(const Image& image, float threshold) {
    Image image2 = Grayscale(image);
    for (int x = 0; x != image2.GetHeight(); ++x) {
        for (int y = 0; y != image2.GetWidth(); ++y) {
            unsigned char rch = static_cast<unsigned char>(image.At(x, y).r_ * 255);
            int32_t r = rch;
            r *= 4;
            r -= static_cast<unsigned char>(image.At(x - 1, y).r_ * 255);
            r -= static_cast<unsigned char>(image.At(x + 1, y).r_ * 255);
            r -= static_cast<unsigned char>(image.At(x, y - 1).r_ * 255);
            r -= static_cast<unsigned char>(image.At(x, y + 1).r_ * 255);

            r = static_cast<unsigned char>(std::clamp(r, 0, 255));

            if (r > threshold) {
                image2.SetColour(Colour(1, 1, 1), x, y);
            } else {
                image2.SetColour(Colour(0, 0, 0), x, y);
            }
        }
    }
    return image2;
}
Image FilterEdgeDetection::Do(const Image& image, std::vector<std::string> parameters) {
    return EdgeDetection(image, std::stof(parameters[0]));
}