#include <iostream>
#include "../image_data/image.h"

int main() {
    Image image = Image(2, 3);

    if (image.GetWidth() != 2) {
        return 1;
    }
    if (image.GetHeight() != 3) {
        return 1;
    }

    std::vector<std::vector<Colour>> pixels = {
        {Colour(1, 1, 1), Colour(1, 1, 1)}, {Colour(0, 0, 0), Colour(1, 0, 0)}, {Colour(0, 1, 0), Colour(0, 0, 1)}};
    Image image2 = Image(2, 3, pixels);
    if (image2.GetPixels() != pixels) {
        return 1;
    }
    if (image2.GetColour(0, 0) != Colour(1, 1, 1)) {
        return 1;
    }
    if (image2.GetWidth() != 2) {
        return 1;
    }
    if (image2.GetHeight() != 3) {
        return 1;
    }
    return 0;
}