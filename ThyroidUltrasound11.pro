#-------------------------------------------------
#
# Project created by QtCreator 2017-09-06T10:40:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThyroidUltrasound
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    showlabel.cpp \
    mythread.cpp \
    testwrapper.cpp

HEADERS  += mainwindow.h \
    showlabel.h \
    ithyroidwrapper.h \
    mythread.h \
    testwrapper.h

FORMS    += mainwindow.ui
INCLUDEPATH += /usr/local/include
LIBS += /usr/local/lib/libopencv_video.so  \
  /usr/local/lib/libopencv_objdetect.so \
  /usr/local/lib/libopencv_ml.so  \
  /usr/local/lib/libopencv_core.so \
  /usr/local/lib/libopencv_features2d.so  \
  /usr/local/lib/libopencv_imgproc.so \
  /usr/local/lib/libopencv_highgui.so \
  /usr/local/lib/libopencv_flann.so   \
  /usr/local/lib/libopencv_calib3d.so \
  /usr/local/lib/libopencv_imgcodecs.so \
  /usr/local/lib/libuvc.so

RESOURCES += \
    resource.qrc
