#include "image_data/image.h"
#include "filters/filters.h"
#include <vector>
#include "parsing/parsing_command_line.h"
#include "parsing/help.h"

int main(int argc, char** argv) {
    std::vector<std::pair<Filter*, std::vector<std::string>>> filters_list;
    std::string path_in;
    std::string path_out;
    Image image;
    try {
        filters_list = Parsing(argc, argv);
        if (argc < 3) {
            print_help();
            return 0;
        }
        path_in = argv[1];
        path_out = argv[2];
        image = ReadBmp(path_in);
        for (auto [filter, parameters] : filters_list) {
            image = filter->Do(image, parameters);
            delete filter;
        }
        SaveBmp(path_out, image);
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}
