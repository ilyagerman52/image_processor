#include "blur.h"
#include <cmath>

Image Blur(const Image& image, const float& sigma) {
    float sigma2 = std::abs(sigma);
    Image image_buf = Image(image.GetWidth(), image.GetHeight());
    Image image2 = Image(image.GetWidth(), image.GetHeight());

    int delta = 3 * sigma2;
    std::vector<decltype(exp(1 / (2 * (sigma * sigma))))> coef;
    coef.reserve(6 * sigma2 + 1);
    for (int i = 0; i != 6 * sigma2 + 1; ++i) {
        coef.push_back(exp(-((i - 3 * sigma2) * (i - 3 * sigma2)) / (2 * (sigma2 * sigma2))));
    }
    float sum_res = 0;
    for (auto i : coef) {
        sum_res += i;
    }

    for (int x = 0; x != image.GetHeight(); ++x) {
        for (int y = 0; y != image.GetWidth(); ++y) {
            int64_t r = 0;
            int64_t g = 0;
            int64_t b = 0;

            for (int i = x - delta; i != x + delta; ++i) {
                r += static_cast<unsigned char>(image.At(i, y).r_ * 255) * coef[i - (x - delta)];
                g += static_cast<unsigned char>(image.At(i, y).g_ * 255) * coef[i - (x - delta)];
                b += static_cast<unsigned char>(image.At(i, y).b_ * 255) * coef[i - (x - delta)];
            }

            r = r / sum_res;
            g = g / sum_res;
            b = b / sum_res;
            r = std::clamp(r, 0ll, 255ll);
            g = std::clamp(g, 0ll, 255ll);
            b = std::clamp(b, 0ll, 255ll);

            image_buf.SetColour(Colour(r / 255.0f, g / 255.0f, b / 255.0f), x, y);
        }
    }

    for (int x = 0; x != image.GetHeight(); ++x) {
        for (int y = 0; y != image.GetWidth(); ++y) {
            int64_t r = 0;
            int64_t g = 0;
            int64_t b = 0;

            for (int i = y - delta; i != y + delta; ++i) {
                r += static_cast<unsigned char>(image_buf.At(x, i).r_ * 255) * coef[i - (y - delta)];
                g += static_cast<unsigned char>(image_buf.At(x, i).g_ * 255) * coef[i - (y - delta)];
                b += static_cast<unsigned char>(image_buf.At(x, i).b_ * 255) * coef[i - (y - delta)];
            }

            r = r / sum_res;
            g = g / sum_res;
            b = b / sum_res;
            r = std::clamp(r, 0ll, 255ll);
            g = std::clamp(g, 0ll, 255ll);
            b = std::clamp(b, 0ll, 255ll);
            image2.SetColour(Colour(r / 255.0f, g / 255.0f, b / 255.0f), x, y);
        }
    }
    return image2;
}
Image FilterBlur::Do(const Image& image, std::vector<std::string> parameters) {
    return Blur(image, std::stof(parameters[0]));
}