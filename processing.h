#ifndef PROCESSING_H
#define PROCESSING_H

#include "mat.h"
#include "rwmat.h"

#include <cmath>
#include <array>
#include <cassert>
#include <complex>
#include <bitset>
#include <memory>
#include <numeric>

namespace  wong{

void move(const BmpMat*, int, int, BmpMat*);
enum class MapType { xTo, xFrom, yTo, yFrom };    //坐标映射类型
int mapLoc(double, int, int, MapType);

void verticallyMirror(const BmpMat*, BmpMat*);
void horizontallyMirror(const BmpMat*, BmpMat*);
void rotate(const BmpMat*, double, BmpMat*, InsertType = InsertType::Neiborhood);
void cut(const BmpMat*, int, int, int, int, BmpMat*);

void swapData(char*, char*, int);
void swapAndZeros(char*, char*, int);

void daoxu(std::vector<int>&, int);

enum class FFTOrIFFTType{FFT, IFFT};
void FFT(char*, int, const std::vector<size_t>&, FFTOrIFFTType flag =  FFTOrIFFTType::FFT);

enum class PadType{RightTop, Center};
void padZeros(BmpMat*, PadType type = PadType::RightTop, int n = 0);

std::pair<size_t, size_t> fftBmpMat(BmpMat*, std::shared_ptr<std::shared_ptr<std::complex<double>[]>[]>&);
void convertFFT2Abs(std::shared_ptr<std::shared_ptr<std::complex<double>[]>[]>, size_t, size_t, BmpMat*);
void ifftBmpMat(const std::shared_ptr<std::shared_ptr<std::complex<double>[]>[]>&, const std::pair<size_t, size_t>, BmpMat*, int oriRows, int oriCols);

enum class FFTFilter{ILPF, BLPF, ELPF, GLPF};
//原图，结果图，中心频率，滤波方式，滤波参数n
void fftFilter(BmpMat*, BmpMat*, int, FFTFilter type = FFTFilter::ILPF, int n = 0);

enum class SpaceFilter{BLF, BHF, BMEDF};
//原图，结果图,滤波方式，滤波掩模大小n
void spaceFilter(BmpMat*, BmpMat*, SpaceFilter type = SpaceFilter::BLF, int n = 3);

void histOfBmpMat(BmpMat *sourceMatPtr, std::shared_ptr<std::vector<int>[]> &histBGR);
void histBalance(const std::vector<int>&, std::vector<int>&, int);
void histReg(const std::vector<int> &oriV, std::vector<int> &resV, const std::vector<double> &regV);
void balance(BmpMat *sourceMatPtr, BmpMat *resultMatPtr, int scale);
void sortMatOnHist(BmpMat*, std::vector<BmpMat*>&);
double figRelation(const std::vector<std::vector<double>>&, const std::vector<std::vector<double>>&);
void doubleHist(const std::shared_ptr<std::vector<int>[]>&, std::vector<std::vector<double>>&);
enum class DCTOrIDCT {
    DCT, IDCT
};
/*
void dct(char *rawDataPtr, int N, const std::vector<size_t> &revPos, DCTOrIDCT flag = DCTOrIDCT::DCT);
void dct2(char *rawDataPtr, int N, int M, const std::vector<size_t> &nRevPos, const std::vector<size_t> &mRevPos, DCTOrIDCT flag = DCTOrIDCT::DCT);
*/

std::shared_ptr<double[]> dct2(double*, int, int, DCTOrIDCT type = DCTOrIDCT::DCT);

void convertDCT2Abs(std::shared_ptr<std::shared_ptr<double[]>[]>, int, int, BmpMat*);

void dctBmpMat(BmpMat*, std::shared_ptr<std::shared_ptr<double[]>[]>&);

void idctBmpMat(std::shared_ptr<std::shared_ptr<double[]>[]>, int, int, BmpMat*);
}


#endif // PROCESSING_H
