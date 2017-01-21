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
    shims.cpp \
    node.cpp \
    scene.cpp \
    RouteLine.cpp

HEADERS  += mainwindow.h \
    shims.h \
    node.h \
    scene.h \
    RouteLine.h

FORMS    += mainwindow.ui
