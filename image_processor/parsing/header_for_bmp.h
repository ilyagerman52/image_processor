#pragma once

#include <string>
#include <fstream>

const int FILE_HEADER_SIZE = 14;
const int INFO_HEADER_SIZE = 40;

void CreatingFileHeader(unsigned char* file_header, const int file_size, const int file_header_size,
                        const int info_header_size) {
    file_header[0] = 'B';
    file_header[1] = 'M';

    file_header[2] = file_size;
    file_header[3] = file_size >> 8;
    file_header[4] = file_size >> 16;
    file_header[5] = file_size >> 24;

    file_header[6] = 0;
    file_header[7] = 0;

    file_header[8] = 0;
    file_header[9] = 0;

    file_header[10] = file_header_size + info_header_size;
    file_header[11] = 0;
    file_header[12] = 0;
    file_header[13] = 0;
}

void CreatingInfoHeader(unsigned char* info_header, int info_header_size, int width, int height) {
    info_header[0] = info_header_size;
    info_header[1] = 0;
    info_header[2] = 0;
    info_header[3] = 0;

    info_header[4] = width;
    info_header[5] = width >> 8;
    info_header[6] = width >> 16;
    info_header[7] = width >> 24;

    info_header[8] = height;
    info_header[9] = height >> 8;
    info_header[10] = height >> 16;
    info_header[11] = height >> 24;

    info_header[12] = 1;
    info_header[13] = 0;

    info_header[14] = 24;
    info_header[15] = 0;

    info_header[16] = 0;
    info_header[17] = 0;
    info_header[18] = 0;
    info_header[19] = 0;

    info_header[20] = 0;
    info_header[21] = 0;
    info_header[22] = 0;
    info_header[23] = 0;

    info_header[24] = 0;
    info_header[25] = 0;
    info_header[26] = 0;
    info_header[27] = 0;

    info_header[28] = 0;
    info_header[29] = 0;
    info_header[30] = 0;
    info_header[31] = 0;

    info_header[32] = 0;
    info_header[33] = 0;
    info_header[34] = 0;
    info_header[35] = 0;

    info_header[36] = 0;
    info_header[37] = 0;
    info_header[38] = 0;
    info_header[39] = 0;
}

std::pair<int, int> ReaderFileHeader(std::ifstream& file) {

    char file_header[FILE_HEADER_SIZE];
    file.read(file_header, FILE_HEADER_SIZE);
    if (file_header[0] != 'B' || file_header[1] != 'M' || file_header[10] != 54) {
        throw std::runtime_error("Current file seems to be not 24-byte bmp");
    }
    char info_header[INFO_HEADER_SIZE];
    file.read(info_header, INFO_HEADER_SIZE);
    if (info_header[0] != 40 || info_header[14] != 24) {
        throw std::runtime_error("Current file seems to be not 24-byte bmp");
    }
    if (info_header[16] != 0 || info_header[17] != 0 || info_header[18] != 0 || info_header[19] != 0) {
        throw std::runtime_error("Compression error");
    }

    int width = static_cast<unsigned char>(info_header[4]) + (static_cast<unsigned char>(info_header[5]) << 8) +
                (static_cast<unsigned char>(info_header[6]) << 16) + (static_cast<unsigned char>(info_header[7]) << 24);

    int height = static_cast<unsigned char>(info_header[8]) + (static_cast<unsigned char>(info_header[9]) << 8) +
                 (static_cast<unsigned char>(info_header[10]) << 16) +
                 (static_cast<unsigned char>(info_header[11]) << 24);

    return {width, height};
}