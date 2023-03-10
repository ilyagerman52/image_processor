#include <iostream>
#include "../parsing/parsing_command_line.h"

int main() {

    Colour black = Colour(0, 0, 0);
    Colour red = Colour(1, 0, 0);
    Colour green = Colour(0, 1, 0);
    Colour blue = Colour(0, 0, 1);
    Colour white = Colour(1, 1, 1);

    std::vector<std::vector<Colour>> pixels = {{black, red, black}, {blue, Colour(0.3f, 0.1f, 0.1f), green}, {black, black, black}};
    Image image = Image(3, 3, pixels);
    FilterSharpening* sharp_ptr = new FilterSharpening;
    Image image2 = sharp_ptr->Do(image, {});
    delete sharp_ptr;

    auto new_pixels = image2.GetPixels();
    if (new_pixels[1][1] != Colour(0.49019608, 0, 0) || new_pixels[0][0] != black || new_pixels[1][2] != green) {
        return 1;
    }
    return 0;
}