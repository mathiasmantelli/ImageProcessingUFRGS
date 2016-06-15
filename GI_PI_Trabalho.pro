#-------------------------------------------------
#
# Project created by QtCreator 2015-09-15T18:23:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GI_PI_Trabalho
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_features2d -lopencv_imgproc

SOURCES += main.cpp\
        mainwindow.cpp \
    algoritmos_pi.cpp

HEADERS  += mainwindow.h \
    algoritmos_pi.h

FORMS    += mainwindow.ui
