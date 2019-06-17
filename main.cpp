#include "mat.h"
#include "rwmat.h"
#include "processing.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[])
{
    std::unique_ptr<wong::BmpMat> sourceMat;
    try {
        sourceMat = readMat("d://testMat//lena.bmp");
    } catch (std::runtime_error& e) {
       std::cout << e.what() << std::endl;
       return 0;
    }
    std::unique_ptr<wong::BmpMat> resultMat(new wong::BmpMat());
    /*
    wong::move(sourceMat.get(), 20, -188, resultMat.get());
    */
    /*
    wong::horizontallyMirror(sourceMat.get(), resultMat.get());
    */
    //wong::rotate(sourceMat.get(), 20, resultMat.get());
    //wong::cut(sourceMat.get(), 2, 2, 100, 100, resultMat.get());
    resultMat->writeMat("d://testMat//resultMat.bmp");
}
