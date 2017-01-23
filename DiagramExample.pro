#-------------------------------------------------
#
# Project created by QtCreator 2016-08-15T16:11:34
#
#-------------------------------------------------

QT += core gui widgets
CONFIG += c++14

TARGET = Test
TEMPLATE = app

HEADERS += $$PWD/*.h
SOURCES += $$PWD/*.cpp

FORMS += mainwindow.ui

include(libavoid/libavoid.pri)
