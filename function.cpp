#include "function.h"
#include <iostream>
#include <string>

unsigned long chArrToLong(char *cur, short size) {

    unsigned long totalL = 0;
    for (short i = 0; i != size; ++i)
    {
        int tmpL = static_cast<int>(*cur);            
        tmpL = tmpL < 0 ? (256 + tmpL) : tmpL;		 
        ++cur;

        tmpL <<= 8 * i;
        totalL += tmpL;
    }

    return totalL;
}

void longToChArr(unsigned long uL, char *source, short size) {

    unsigned long uL1 = 0;
    for (size_t i = 0; i != size; ++i)
    {
        unsigned long mask = 255;
        mask <<= 8 * i;
        uL1 = uL & mask;
        uL1 >>= 8 * i;
        *(source + i) = static_cast<char>(uL1);
    }

    return;
}

char strToch(const std::string &str) {
    int asc = 0;
    constexpr int len = 8;
    for (size_t i = 0; i != len; ++i) {
        asc += std::pow(2, i) * std::stoi(str.substr(len - 1 - i, 1));
    }
    return static_cast<char>(asc);
}


