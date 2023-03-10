#pragma once

#include "filters.h"

Image Blur(const Image& image, const float& sigma2);

class FilterBlur : public Filter {
public:
    Image Do(const Image& image, std::vector<std::string>) override;
    ~FilterBlur() override = default;
};