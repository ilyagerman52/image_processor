#pragma once

#include <string>
#include <vector>
#include "colour.h"

using Pixels = std::vector<std::vector<Colour>>;

class Image {
public:
    Image(int width, int height);
    Image();
    Image(int width, int height, Pixels colours);
    ~Image() = default;

    Colour At(const int x, const int y) const;
    Colour GetColour(const int x, const int y) const;
    void SetColour(Colour colour, const int x, const int y);
    int GetWidth() const;
    int GetHeight() const;
    const Pixels& GetPixels() const;

    bool operator==(const Image&) const;

    friend Image ReadBmp(const std::string& path);
    friend void SaveBmp(const std::string& path, const Image& image);

private:
    int width_;
    int height_;
    Pixels colours_;
};


