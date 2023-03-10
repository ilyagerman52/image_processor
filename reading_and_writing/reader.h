#pragma once

#include <string>
#include "../image_data/image.h"

void SaveBmp(const std::string& path, const Image& image);
Image ReadBmp(const std::string& path);