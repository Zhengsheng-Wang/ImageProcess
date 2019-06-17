#ifndef FUNCTION_H
#define FUNCTION_H

#include <complex>
#include "Mat.h"

unsigned long chArrToLong(char*, short);			//将字符串转化为长整型

void longToChArr(unsigned long, char *, short);     //将长整型转化为字符串

char strToch(const std::string &str);              //

//将二维FFT得到的结果Res转换成幅值，好作为图像输出
void convertFFTToAbs(std::shared_ptr<std::shared_ptr<std::complex<double>[]>[]>,
                     wong::BmpMat*);

#endif // FUNCTION_H
