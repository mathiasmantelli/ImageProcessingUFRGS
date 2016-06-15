#include "mainwindow.h"
#include <QApplication>
#include <mainwindow.h>

using namespace cv;
using namespace std;
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
//}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mw;
    Algoritmos_PI api;
    api.Open("/home/mathias/Downloads/4.jpg");
    mw.show();

    return a.exec();
}
