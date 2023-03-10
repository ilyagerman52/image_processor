cmake_minimum_required(VERSION 3.17)
project(image_processor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(PROJECT_FILES
        image_data/colour.h image_data/colour.cpp
        image_data/image.h image_data/image.cpp
        reading_and_writing/reader.h reading_and_writing/reader.cpp
        parsing/header_for_bmp.h
        parsing/help.h
        parsing/parsing_command_line.h
        filters/filters.h
        filters/negative.cpp filters/negative.h
        filters/grayscale.cpp filters/grayscale.h
        filters/sharpening.cpp filters/sharpening.h
        filters/crop.cpp filters/crop.h
        filters/edge_detection.cpp filters/edge_detection.h
        filters/blur.cpp filters/blur.h
        filters/mosaic.cpp filters/mosaic.h
        )

add_executable(image_processor
        ${PROJECT_FILES}
        image_processor.cpp
        )

function(create_test test_name)
    add_executable(${test_name}
            ${PROJECT_FILES}
            tests/${test_name}.cpp
            )
    target_include_directories(${test_name} PUBLIC .)
    add_test(${test_name} ${test_name})
endfunction()

enable_testing()

create_test(test_image_constructor)
create_test(test_colour)
create_test(test_crop)
create_test(test_negative)
create_test(test_grayscale)
create_test(test_sharp)
create_test(test_edge)
create_test(test_blur)
create_test(test_mosaic)
create_test(test_parsing)

