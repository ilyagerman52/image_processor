#pragma once

#include "filters.h"

Image Grayscale(const Image& image);

class FilterGrayscale : public Filter {
public:
    Image Do(const Image& image, std::vector<std::string>) override;
    ~FilterGrayscale() override = default;
};