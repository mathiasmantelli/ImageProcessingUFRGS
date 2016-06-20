#include <opencv2/core/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <QImage>


#ifndef ALGORITMOS_PI_H
#define ALGORITMOS_PI_H

using namespace std;
using namespace cv;

class Algoritmos_PI
{
public:
    Algoritmos_PI();
    void Show_Img(bool flag);
    Mat Mirror_Vertic_Img(Mat img);
    Mat Mirror_Horizon_Img(Mat img);
    Mat Conver2Gray_Img(Mat img);
    void Save_Img(Mat img);
    void Save_Img2(Mat img);
    Mat Luminance_Img(Mat img, int value);
    Mat Contrast_Img(Mat img, float value);
    Mat Quantization(Mat img,int value);
    Mat Open(String endereco);
    Mat Histograma(Mat img);
    Mat Negative(Mat img);
    Mat Equalization(Mat img);
    void Histograma_RGB(Mat img);
    void setImage(Mat img);
    void set_Flag_Abrir(bool n);
    void set_Flag_Copia(bool n);
    void set_Flag_Cinza(bool n);
    bool get_Flag_Abrir();
    bool get_Flag_Copia();
    bool get_Flag_Cinza();
    Mat getImage();
    QImage Mat2QImage(cv::Mat const& src);

    Mat f(Mat img);

    Mat image_input;
    Mat image_work;

    bool flag_abrir,flag_copia, flag_cinza;
    static QImage r,g,b;
};

#endif // ALGORITMOS_PI_H
