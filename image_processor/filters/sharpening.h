#pragma once

#include "filters.h"

Image Sharpening(const Image& image);

class FilterSharpening : public Filter {
public:
    Image Do(const Image& image, std::vector<std::string>) override;
    ~FilterSharpening() override = default;
};

