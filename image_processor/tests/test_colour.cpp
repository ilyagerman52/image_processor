#include <iostream>
#include "../image_data/image.h"

int main() {
    Colour black = Colour(0, 0, 0);
    Colour red = Colour(1, 0, 0);
    Colour blue = Colour(0, 0, 1);

    if (black.r_ != 0 || black.g_ != 0 || black.b_ != 0) {
        return 1;
    }
    if (red.b_ != 0) {
        return 1;
    }
    blue.b_ -= 1;
    blue.r_ += 1;
    if (blue != red || red != blue) {
        return 1;
    }
    return 0;
}