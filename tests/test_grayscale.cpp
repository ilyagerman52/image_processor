#include "../image_data/image.h"
#include "../filters/grayscale.h"

int main() {
    Colour black = Colour(0, 0, 0);
    Colour red = Colour(1, 0, 0);
    Colour green = Colour(0, 1, 0);
    Colour blue = Colour(0, 0, 1);
    Colour white = Colour(1, 1, 1);

    std::vector<std::vector<Colour>> pixels = {
        {green, Colour(1, 1, 0)}};
    Image image = Image(2, 1, pixels);
    FilterGrayscale* negative_ptr = new FilterGrayscale;
    Image image2 = negative_ptr->Do(image, {});
    delete negative_ptr;

    auto new_pixels = image2.GetPixels();
    if (new_pixels[0][0] != Colour(0.587f, 0.587f, 0.587f) || new_pixels[0][1] != Colour(0.886f, 0.886f, 0.886f)) {
        return 1;
    }
    return 0;
}