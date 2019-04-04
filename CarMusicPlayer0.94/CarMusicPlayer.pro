#-------------------------------------------------
#
# Project created by QtCreator 2018-07-11T09:15:22
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CarMusicPlayer
TEMPLATE = app


SOURCES += main.cpp\
    setthreshold.cpp \
    testform.cpp \
    cameracap.cpp \
    carmusic.cpp \
    mainwindow.cpp \
    display.cpp \
    sensor.cpp \
    communication.cpp \
    udpreceiver.cpp \
    udpsender.cpp \
    imageview.cpp

HEADERS  += \
    setthreshold.h \
    testform.h \
    cameracap.h \
    carmusic.h \
    mainwindow.h \
    display.h \
    sensor.h \
    communication.h \
    udpreceiver.h \
    udpsender.h \
    imageview.h

FORMS    += \
    setthreshold.ui \
    testform.ui \
    cameracap.ui \
    carmusic.ui \
    mainwindow.ui \
    display.ui \
    imageview.ui

CONFIG += mobility
MOBILITY =
#LIBS     += -lwiringPi
RESOURCES += \
    image.qrc
