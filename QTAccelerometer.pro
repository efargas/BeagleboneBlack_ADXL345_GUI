#-------------------------------------------------
#
# Project created by QtCreator 2014-08-07T17:14:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTAccelerometer
    target.files = QTAccelerometer
    target.path = /home/root/projects/qt-projects

INSTALLS += target
TEMPLATE = app

INCLUDEPATH+=/../../workspace/ADXL345Accelerometer/src

SOURCES += main.cpp\
        mainwindow.cpp \
    ../../../workspace/ADXL345Accelerometer/src/ADXL345Accelerometer.cpp

HEADERS  += mainwindow.h \
    ../../../workspace/ADXL345Accelerometer/src/ADXL345Accelerometer.h

FORMS    += mainwindow.ui
