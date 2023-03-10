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
    FilterEdgeDetection* edge_ptr = new FilterEdgeDetection;
    Image image2 = edge_ptr->Do(image, {"10"});
    delete edge_ptr;

    auto new_pixels = image2.GetPixels();
    if (new_pixels[0][0] != black || new_pixels[0][1] != black || new_pixels[0][2] != black ||
        new_pixels[1][0] != black || new_pixels[1][1] != white || new_pixels[1][2] != white ||
        new_pixels[2][0] != black || new_pixels[2][1] != white) {
        return 1;
    }

    FilterEdgeDetection* edge2_ptr = new FilterEdgeDetection;
    Image image3 = edge2_ptr->Do(image, {"1000"});
    delete edge2_ptr;
    auto new2_pixels = image3.GetPixels();
    if (new2_pixels[0][0] != black || new2_pixels[0][1] != black || new2_pixels[0][2] != black ||
        new2_pixels[1][0] != black || new2_pixels[1][1] != black || new2_pixels[1][2] != black ||
        new2_pixels[2][0] != black || new2_pixels[2][1] != black || new2_pixels[2][2] != black ||
        new2_pixels[3][0] != black || new2_pixels[3][1] != black || new2_pixels[3][2] != black) {
        return 1;
    }


    return 0;
}