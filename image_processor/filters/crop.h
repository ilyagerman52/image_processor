#pragma once

#include "filters.h"

Image Crop(const Image& image, int down, int right);

class FilterCrop : public Filter {
public:
    Image Do(const Image& image, std::vector<std::string>) override;
    ~FilterCrop() override = default;
};