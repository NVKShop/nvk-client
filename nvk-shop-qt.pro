#-------------------------------------------------
#
# Project created by QtCreator 2016-09-27T13:05:11
#
#-------------------------------------------------

QT       += core widgets network

TARGET = nvk-shop-qt
TEMPLATE = app

SOURCES += main.cpp\
        NVKMainWindow.cpp \
    NetworkHandler.cpp \
    HttpHandler.cpp \
    User.cpp \
    Cart.cpp \
    Order.cpp \
    ProductsScene.cpp \
    ProductsView.cpp \
    Product.cpp \
    Property.cpp \
    UserProperty.cpp \
    ProductProperty.cpp \
    NVKController.cpp \
    JsonRequest.cpp \
    JsonReply.cpp \
    JsonQuery.cpp \
    LoginWindow.cpp \
    CategoriesView.cpp \
    UserPanelView.cpp \
    UserPanelScene.cpp \
    CategoriesScene.cpp \
    Category.cpp \
    UserPanelItem.cpp \
    Address.cpp

HEADERS  += NVKMainWindow.h \
    NetworkHandler.h \
    HttpHandler.h \
    User.h \
    Cart.h \
    Order.h \
    ProductsScene.h \
    ProductsView.h \
    Product.h \
    Property.h \
    UserProperty.h \
    ProductProperty.h \
    NVKController.h \
    JsonRequest.h \
    JsonReply.h \
    JsonQuery.h \
    LoginWindow.h \
    CategoriesView.h \
    UserPanelView.h \
    UserPanelScene.h \
    CategoriesScene.h \
    Category.h \
    UserPanelItem.h \
    Address.h

FORMS    += nvkmainwindow.ui \
    loginwindow.ui

CONFIG += mobility qt
CONFIG += C++11
MOBILITY = 

DISTFILES +=

RESOURCES += \
    images.qrc


