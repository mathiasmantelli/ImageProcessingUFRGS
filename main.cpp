#include "mainwindow.h"
#include <QApplication>
#include <mainwindow.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mw;
    Algoritmos_PI api;
    api.Open("/home/mathias/Downloads/4.jpg");
    mw.show();

    return a.exec();
}


//void color_reduce(cv::Mat &input, cv::Mat &output, size_t div)
//{
//    if(input.data != output.data){
//        output.create(input.size(), input.type());
//    }

//    uchar buffer[256];
//    for(size_t i = 0; i != 256; ++i){
//        buffer[i] = i / div * div + div / 2;
//    }
//    cv::Mat table(1, 256, CV_8U, buffer, sizeof(buffer));
//    cv::LUT(input, table, output);
//}

//int main()
//{
//    cv::Mat src = cv::imread("/home/mathias/Downloads/4.jpg");
//    if (src.empty()){
//        std::cerr<<"can't open image"<<std::endl;
//        return - 1;
//    }

//    cv::Mat output;
//    color_reduce(src, output, 100);

//    cv::imshow("result", output);
//    cv::imshow("src", src);
//    cv::waitKey();

//    return 0;
//}
