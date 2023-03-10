#include <iostream>
#include "../parsing/parsing_command_line.h"

int main() {

    Colour black = Colour(0, 0, 0);
    Colour red = Colour(1, 0, 0);
    Colour green = Colour(0, 1, 0);
    Colour blue = Colour(0, 0, 1);
    Colour white = Colour(1, 1, 1);

    std::vector<std::vector<Colour>> pixels = {
        {black, green, black}, {green, white, white}, {blue, red, black}, {white, white, black}};
    Image image = Image(3, 4, pixels);
    FilterBlur* blur_ptr = new FilterBlur;
    Image image2 = blur_ptr->Do(image, {"3"});
    delete blur_ptr;

    auto new_pixels = image2.GetPixels();
    if (new_pixels[0][2].b_ != 0.2f || new_pixels[1][0].b_ != 1.0f / 3 ||
        new_pixels[1][2] != Colour(0.23137255, 0.309803933, 0.254901975)) {
        return 1;
    }
    return 0;
}