#pragma once

#include "filters.h"

Image EdgeDetection(const Image& image, unsigned char threshold);

class FilterEdgeDetection : public Filter {
public:
    Image Do(const Image& image, std::vector<std::string>) override;
    ~FilterEdgeDetection() override = default;
};