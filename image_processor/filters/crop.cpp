#include "crop.h"

Image Crop(const Image& image, int right, int down) {
    int down2 = std::min(down, image.GetHeight());
    int right2 = std::min(right, image.GetWidth());
    Image image2 = Image(right2, down2);
    for (int x = image.GetHeight() - down2; x != image.GetHeight(); ++x) {
        for (int y = 0; y != right2; ++y) {
            Colour colour = image.GetColour(x, y);
            image2.SetColour(colour, x - image.GetHeight() + down2, y);
        }
    }

    return image2;
}

Image FilterCrop::Do(const Image& image, std::vector<std::string> parameters) {
    return Crop(image, std::stoi(parameters[0]), std::stoi(parameters[1]));
}
