#pragma once

#include <iostream>

int print_help() { //NOLINT
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "Первый вводимый параметр - путь, откуда будет взят файл BMP" << std::endl;
    std::cout << "Второй вводимый параметр - путь, куда будет сохранён результат обработки изображения" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Фильтры:" << std::endl;
    std::cout << "Для обрезки изображения используйте -crop и параметры (высота и ширина)" << std::endl;
    std::cout << "Для фильтра NEGATIVE используйте -neg без параметров" << std::endl;
    std::cout << "Для фильтра GRAYSCALE используйте -gs без параметров" << std::endl;
    std::cout << "Для фильтра SHARPENING используйте -sharp без параметров" << std::endl;
    std::cout << "Для фильтра EDGEDETECTION используйте -edge с параметром threshold" << std::endl;
    std::cout << "Для фильтра BLUR используйте -blur с параметром размытия sigma" << std::endl;
    std::cout << "Для фильтра MOSAIC используйте -mos с параметром, равным размеру квадратиков в мазаике" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;

    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;

    return 0;
//    std::cout << "code isn't appropriate for you goals" << std::endl;
}