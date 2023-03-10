#include "reader.h"
#include <iostream>
#include "../image_data/image.h"
#include "../parsing/header_for_bmp.h"


void SaveBmp(const std::string& path, const Image& image) {
    std::ofstream file;
    file.open(path, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("file wasn't saved");
    }

    unsigned char bmp_pad[3] = {0, 0, 0};
    const int padding_amount = ((4 - (image.width_ * 3) % 4) % 4);

    const int file_size =
        FILE_HEADER_SIZE + INFO_HEADER_SIZE + image.width_ * image.height_ * 3 + padding_amount * image.height_;

    unsigned char file_header[FILE_HEADER_SIZE];
    CreatingFileHeader(file_header, file_size, FILE_HEADER_SIZE, INFO_HEADER_SIZE);
    unsigned char info_header[INFO_HEADER_SIZE];
    CreatingInfoHeader(info_header, INFO_HEADER_SIZE, image.width_, image.height_);
    file.write(reinterpret_cast<char*>(file_header), FILE_HEADER_SIZE);
    file.write(reinterpret_cast<char*>(info_header), INFO_HEADER_SIZE);
    for (int x = 0; x != image.height_; ++x) {
        for (int y = 0; y != image.width_; ++y) {
            unsigned char pixel_r = image.GetColour(x, y).r_ * 255.0f;
            unsigned char pixel_g = image.GetColour(x, y).g_ * 255.0f;
            unsigned char pixel_b = image.GetColour(x, y).b_ * 255.0f;

            unsigned char pixel[] = {pixel_b, pixel_g, pixel_r};

            file.write(reinterpret_cast<char*>(pixel), 3);
        }
        file.write(reinterpret_cast<char*>(bmp_pad), padding_amount);
    }

    file.close();
}

Image ReadBmp(const std::string& path) {
    Image image = Image(0, 0);
    std::ifstream file;
    file.open(path, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("file wasn't read");
    }

    std::pair<int, int> parameters = ReaderFileHeader(file);
    image.width_ = parameters.first;
    image.height_ = parameters.second;

    const int padding_amount = ((4 - (image.width_ * 3) % 4) % 4);

    image.colours_.reserve(image.height_);
    std::vector<Colour> colour_row = std::vector<Colour>(image.width_);
    for (int i = 0; i != image.height_; ++i) {
        image.colours_.push_back(colour_row);
    }

    for (int x = 0; x != image.height_; ++x) {
        for (int y = 0; y != image.width_; ++y) {
            char buffer[3];
            file.read(buffer, 3);
            image.SetColour(Colour(buffer[2] / 255.0f, buffer[1] / 255.0f, buffer[0] / 255.0f), x, y);
        }
        char buffer2[padding_amount];
        file.read(buffer2, padding_amount);
    }
    return image;
}
