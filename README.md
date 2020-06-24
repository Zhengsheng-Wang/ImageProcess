# ImageProcess
数字图像处理软件源码

该源码实现的对bmp格式的数字图像进行处理的功能如下：
1. 移动
2. 镜像
3. 旋转
4. 剪切
5. 基于快速傅里叶变换的频域滤波
6. 空域滤波
7. 直方图均衡化

完成上述功能的函数定义在头文件processing.h中，在function.cpp中实现。

mat.h定义了表示bmp格式图像的类，mat.cpp实现了类的成员函数。

rwmat.h和rwmat.cpp分别声明和实现了bmp图像的读写功能。
