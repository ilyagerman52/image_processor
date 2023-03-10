#include <iostream>
#include "../parsing/parsing_command_line.h"

int main() {

    Colour black = Colour(0, 0, 0);
    Colour red = Colour(1, 0, 0);
    Colour green = Colour(0, 1, 0);
    Colour blue = Colour(0, 0, 1);
    Colour white = Colour(1, 1, 1);

    std::vector<std::vector<Colour>> pixels = {
        {black, green, black, red, red, red, red, red, blue, green},
        {green, white, white, blue, red, green, blue, white, green, white},
        {blue, red, black, white, black, blue, black, white, black, blue},
        {white, white, black, white, white, green, blue, blue, green, white},
        {white, white, black, white, white, green, blue, blue, green, white},
        {white, white, black, white, white, green, blue, blue, green, white},
        {white, white, black, white, white, green, blue, blue, green, white},
        {white, white, black, white, white, green, blue, blue, green, white},
        {white, white, black, white, white, green, blue, blue, green, white}};
    Image image = Image(10, 9, pixels);
    FilterMosaic* mosaic_ptr = new FilterMosaic;
    Image image2 = mosaic_ptr->Do(image, {"2"});
    delete mosaic_ptr;

    auto new_pixels = image2.GetPixels();
    if (new_pixels[0][0] != black || new_pixels[0][1] != black || new_pixels[0][2] != black ||
        new_pixels[1][0] != black || new_pixels[4][4] != white || new_pixels[4][6] != blue) {
        return 1;
    }
    return 0;
}