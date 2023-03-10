#include <iostream>
#include "../parsing/parsing_command_line.h"

int main() {

    Colour black = Colour(0, 0, 0);
    Colour red = Colour(1, 0, 0);
    Colour green = Colour(0, 1, 0);
    Colour blue = Colour(0, 0, 1);
    Colour white = Colour(1, 1, 1);

    std::vector<std::vector<Colour>> pixels = {{black, green, black},{green, white, white},{blue, red, black},{white, white, black}};
    Image image = Image(3, 4, pixels);
    FilterCrop* crop_ptr = new FilterCrop;
    Image image2 = crop_ptr->Do(image, {"2", "2"});
    delete crop_ptr;

    if (image2.GetHeight() != 2 || image2.GetHeight() != 2) {
        return 1;
    }
    auto new_pixels = image2.GetPixels();
    if (new_pixels[0][0] != blue || new_pixels[0][1] != red || new_pixels[1][0] != white || new_pixels[1][1] != white) {
        return 1;
    }
    return 0;


}