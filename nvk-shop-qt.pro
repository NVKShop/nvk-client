#-------------------------------------------------
#
# Project created by QtCreator 2016-09-27T13:05:11
#
#-------------------------------------------------

QT       += core  widgets location positioning network

TARGET = nvk-shop-qt
TEMPLATE = app


SOURCES += main.cpp\
        NVKMainWindow.cpp \
    NetworkHandler.cpp

HEADERS  += NVKMainWindow.h \
    NetworkHandler.h

FORMS    += nvkmainwindow.ui

CONFIG += mobility
MOBILITY = 

