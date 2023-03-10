#pragma once

#include "filters.h"

Image Negative(const Image& image);

class FilterNegative : public Filter {
public:
    Image Do(const Image& image, std::vector<std::string>) override;
    ~FilterNegative() override = default;
};

