#ifndef MAT_H
#define MAT_H

#include <vector>

namespace wong {

enum class InsertType { Neiborhood, DoubleLine};  //插值方式
//Mat_bmp 存放图片类
class BmpMat{

    private:
        //行和列的数量
        int height, width;
        //图像大小
        int size;
        //图像每一行的字节数
        int bytesOfRow;
        //指向数据的指针
        std::unique_ptr<char[]> rgbData = nullptr;
        //图像的文件头
        std::vector<char> bmpHeader; //用vector存储bmp文件头
        //图像头信息的二进制表示
        std::string headerData = "010000100100110111110110110110110000110000000000000000000000000000000000000000000011011000000000000000000000000000101000000000000000000000000000000101000000001000000000000000000001000000000010000000000000000000000001000000000001100000000000000000000000000000000000000000000100000001001001000001000000000011000100000011100000000000000000110001000000111000000000000000000000000000000000000000000000000000000000000000000000000000000000";

    public:
        BmpMat() : height(0), width(0), size(0), bytesOfRow(0), bmpHeader(0){}
        BmpMat(int, int);
        BmpMat(const BmpMat&);
        BmpMat& operator=(const BmpMat&);
        BmpMat& operator=(BmpMat &&) noexcept;
        ~BmpMat();


        void initRgbData();
        void freshSize();
        void freshBmpHeader();

        void resize(int height, int width, InsertType = InsertType::Neiborhood);              //通过重设行数和列数重整大小，默认邻域插值法
        void resize(double rowR, double colR, InsertType = InsertType::Neiborhood);      //通过设置缩放因子重整大小,默认邻域插值法
        void resize(double r, InsertType = InsertType::Neiborhood);                   //通过设置整幅图像的缩放因子诚征大小

        char *at(int, int); //返回在（x，y）处的像素值，以char类型返回
        std::array<char, 3> ptr(float, float, InsertType = InsertType::Neiborhood) const; //返回（x，y）处的像素值，当点（x，y）不存在的时候返回（255，255，255）
        std::array<int, 3> matVal(int y, int x) const;

        int getHeight() const;
        int getWidth() const;
        int getSize() const;

        char* getRgbData() const;

        bool isNull() const;

        void writeMat(const std::string);

};
}


#endif // MAT_H
