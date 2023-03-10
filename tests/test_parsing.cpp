#include "../parsing/parsing_command_line.h"
#include <vector>

int main() {
    int argc = 16;
    const char* argv[] = {
        "16",
        "path_in",
        "path_out",
        "-blur",
        "2",
        "-crop",
        "2",
        "1",
        "-gs",
        "-neg",
        "-neg",
        "-mos",
        "4",
        "-sharp",
        "-edge",
        "15",
    };
    std::vector<std::pair<Filter*, std::vector<std::string>>> filters_list = Parsing(argc, const_cast<char**>(argv));
    std::vector<std::string> vec = {"2"};
    if (filters_list[0].second != vec) {
        return 1;
    }
    vec = {"2","1"};
    if (filters_list[1].second != vec) {
        return 1;
    }
    vec = {};
    if (filters_list[2].second != vec) {
        return 1;
    }
    if (filters_list[3].second != vec) {
        return 1;
    }
    if (filters_list[4].second != vec) {
        return 1;
    }
    vec = {"4"};
    if (filters_list[5].second != vec) {
        return 1;
    }
    vec = {};
    if (filters_list[6].second != vec ) {
        return 1;
    }
    vec = {"15"};
    if (filters_list[7].second != vec) {
        return 1;
    }
    return 0;
}