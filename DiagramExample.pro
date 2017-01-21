#-------------------------------------------------
#
# Project created by QtCreator 2016-08-15T16:11:34
#
#-------------------------------------------------

include(libavoid/libavoid.pri)

QT       += core gui
CONFIG += c++14z

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphicsViewPlaying
TEMPLATE = app
DEFINES += _AFXDLL

SOURCES += main.cpp\
        mainwindow.cpp \
    node.cpp \
    scene.cpp \
    utils.cpp \
    pathline.cpp

HEADERS  += mainwindow.h \
    node.h \
    scene.h \
    utils.h \
    pathline.h

FORMS    += mainwindow.ui
