#pragma once

#include "../image_data/image.h"

class Filter {
public:
    virtual Image Do(const Image& image, std::vector<std::string>) = 0;
    virtual ~Filter() {};
};



Image Id(const Image& image);
Image Malevich(const Image& image);
