#pragma once

#include "filters.h"

Image MyFilter(const Image& image);

class FilterMosaic : public Filter {
public:
    Image Do(const Image& image, std::vector<std::string>) override;
    ~FilterMosaic() override = default;
};