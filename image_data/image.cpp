#include "image.h"
#include <vector>
#include "../reading_and_writing/reader.h"
#include <algorithm>

Image::Image(int width, int height) : width_(width), height_(height) {
    colours_.reserve(height_);
    std::vector<Colour> colour_row = std::vector<Colour>(width_);
    for (int i = 0; i != height_; ++i) {
        colours_.push_back(colour_row);
    }
}
Image::Image() : width_(0), height_(0){};
Image::Image(int width, int height, std::vector<std::vector<Colour>> colours)
    : width_(width), height_(height), colours_(colours) {
}

Colour Image::GetColour(const int x, const int y) const {
    return colours_[x][y];
}

void Image::SetColour(Colour colour, const int x, const int y) {
    colours_[x][y] = colour;
}

int Image::GetWidth() const {
    return this->width_;
}

int Image::GetHeight() const {
    return this->height_;
}

bool Image::operator==(const Image& other) const {
    if (width_ != other.width_ || height_ != other.height_) {
        return false;
    }
    return colours_ == other.colours_;
}

const Pixels& Image::GetPixels() const {
    return colours_;
}

Colour Image::At(const int x, const int y) const {
    auto x2 = std::clamp(x, 0, height_ - 1);
    auto y2 = std::clamp(y, 0, width_ - 1);
    return this->GetColour(x2, y2);
}

