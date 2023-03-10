#include <iostream>
#include "mosaic.h"

Image Mosaic(const Image& image, std::vector<std::string> parameters) {
    int square_size;
    try{
        square_size = std::stoi(parameters[0]);
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid command line argument" << std::endl;
        return Image();
    }
    if (square_size > std::min(image.GetWidth(), image.GetHeight()) / 4) {
        std::cout << "Invalid command line argument" <<std::endl;
        return Image();
    }

    Image image2 = image;

    for (int x = 0; x != image.GetHeight(); ++x) {
        for (int y = 0; y != image.GetWidth(); ++y) {
            if (x < square_size || y < square_size || image.GetHeight() - x < square_size || image.GetWidth() - y < square_size) {
                image2.SetColour(Colour(0, 0, 0), x, y);
            } else if (x % square_size == square_size - 1 || y % square_size == square_size - 1) {
                image2.SetColour(Colour(0, 0, 0), x, y);
            } else if (x % square_size == 0 && y % square_size == 0) {
                unsigned char rch = static_cast<unsigned char>(0);
                unsigned char gch = static_cast<unsigned char>(0);
                unsigned char bch = static_cast<unsigned char>(0);
                int64_t r = rch;
                int64_t g = gch;
                int64_t b = bch;
                int counter = 0;
                for (int i = x; i != std::min(x + square_size - 1, image.GetHeight()); ++i) {
                    for (int j = y; j != std::min(y + square_size - 1, image.GetWidth()); ++j) {
                        r += static_cast<unsigned char>(image.At(i, j).r_ * 255);
                        g += static_cast<unsigned char>(image.At(i, j).g_ * 255);
                        b += static_cast<unsigned char>(image.At(i, j).b_ * 255);
                        ++counter;
                    }
                }

                r = r / counter;
                g = g / counter;
                b = b / counter;

                r = std::clamp(r, 0ll, 255ll);
                g = std::clamp(g, 0ll, 255ll);
                b = std::clamp(b, 0ll, 255ll);
                for (int i = x; i != std::min(x + square_size - 1, image.GetHeight()); ++i) {
                    for (int j = y; j != std::min(y + square_size - 1, image.GetWidth()); ++j) {
                        image2.SetColour(Colour(r / 255.0f, g / 255.0f, b / 255.0f), i, j);
                    }
                }
            }
        }
    }

    return image2;
}

Image FilterMosaic::Do(const Image& image, std::vector<std::string> parameters) {
    return Mosaic(image, parameters);
}