#include "rwmat.h"
#include "function.h"
#include "mat.h"
#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>

using wong::BmpMat;

std::unique_ptr<BmpMat> readMat(const std::string fileName) {
    //读图

    std::ifstream r;
    r.open(fileName, std::ifstream::in | std::ifstream::binary);

    try {
        if(!r.is_open()){
            //如果文件打开失败

            throw std::runtime_error("no associative file");
        }
    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        throw;
    }

    r.seekg(18);
    char widthArr[4];
    r.read(widthArr, 4);
    int width = static_cast<int>(chArrToLong(widthArr, 4));

    char heightArr[4];
    r.read(heightArr, 4);
    int height = static_cast<int>(chArrToLong(heightArr, 4));

    std::unique_ptr<BmpMat> mat(new BmpMat(height, width));

    r.seekg(10);
    char dataOffsetArr[4];				//位图数据偏移量
    r.read(dataOffsetArr, 4);
    int dataOffset = static_cast<int>(chArrToLong(dataOffsetArr, 4));
    r.seekg(dataOffset);

    r.read(mat->getRgbData(), mat->getSize());

    r.close();

    return mat;
}
