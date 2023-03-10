#pragma once

#include <stdexcept>
#include "../image_data/image.h"
#include "../filters/filters.h"
#include "../reading_and_writing/reader.h"

#include "../filters/crop.h"
#include "../filters/grayscale.h"
#include "../filters/negative.h"
#include "../filters/sharpening.h"
#include "../filters/edge_detection.h"
#include "../filters/blur.h"
#include "../filters/mosaic.h"

auto Parsing(int argc, char** argv) {
    std::vector<std::pair<Filter*, std::vector<std::string>>> filter_list;

    if (argc < 2) {
        return filter_list;
    }

    for (int i = 3; i < argc; ++i) {
        std::string argument = argv[i];
        if (argument == "-crop") {
            if (i > argc - 3) {
                throw std::runtime_error("Reading command line parameters was failed");
            }
            std::vector<std::string> parameters = {argv[i + 1], argv[i + 2]};
            try {
                std::stoi(parameters[0]);
                std::stoi(parameters[1]);
            } catch (const std::invalid_argument& e) {
                throw std::runtime_error("Invalid command line argument");
            }
            ++ ++i;
            FilterCrop* filter_crop_ptr = new FilterCrop;
            filter_list.push_back(std::make_pair(filter_crop_ptr, parameters));
        } else if (argument == "-gs") {
            FilterGrayscale* filter_grayscale_ptr = new FilterGrayscale;
            std::vector<std::string> parameters = {};
            filter_list.push_back(std::make_pair(filter_grayscale_ptr, parameters));
        } else if (argument == "-neg") {
            FilterNegative* filter_negative_ptr = new FilterNegative;
            std::vector<std::string> parameters = {};
            filter_list.push_back(std::make_pair(filter_negative_ptr, parameters));
        } else if (argument == "-sharp") {
            FilterSharpening* filter_sharp_ptr = new FilterSharpening;
            std::vector<std::string> parameters = {};
            filter_list.push_back(std::make_pair(filter_sharp_ptr, parameters));
        } else if (argument == "-edge") {
            if (i > argc - 2) {
                throw std::runtime_error("Reading command line parameters was failed");
            }
            std::vector<std::string> parameters = {argv[i + 1]};
            try {
                std::stof(parameters[0]);
            } catch (const std::invalid_argument& e) {
                throw std::runtime_error("Invalid command line argument");
            }
            ++i;
            FilterEdgeDetection* filter_edge_ptr = new FilterEdgeDetection;
            filter_list.push_back(std::make_pair(filter_edge_ptr, parameters));
        } else if (argument == "-blur") {
            if (i > argc - 2) {
                throw std::runtime_error("Reading command line parameters was failed");
            }
            std::vector<std::string> parameters = {argv[i + 1]};
            try {
                std::stof(parameters[0]);
            } catch (const std::invalid_argument& e) {
                throw std::runtime_error("Invalid command line argument");
            }
            ++i;
            FilterBlur* filter_blur_ptr = new FilterBlur;
            filter_list.push_back(std::make_pair(filter_blur_ptr, parameters));
        } else if (argument == "-mos") {
            FilterMosaic* filter_mosaic_ptr = new FilterMosaic;
            std::vector<std::string> parameters = {argv[i + 1]};
            try {
                std::stoi(parameters[0]);
            } catch (const std::invalid_argument& e) {
                throw std::runtime_error("Invalid command line argument");
            }
            ++i;
            filter_list.push_back(std::make_pair(filter_mosaic_ptr, parameters));
        } else {
            throw std::runtime_error("Reading command line parameters was failed");
        }
    }
    return filter_list;
}