#-------------------------------------------------
#
# Project created by QtCreator 2016-09-27T13:05:11
#
#-------------------------------------------------

QT       += core widgets network

TARGET = nvk-shop-qt
TEMPLATE = app

SOURCES += main.cpp\
    backend/controllers/ForgotUserDataController.cpp \
    backend/controllers/LoginController.cpp \
    backend/controllers/PlaceOrderController.cpp \
    backend/controllers/ManageOrderController.cpp \
    backend/controllers/ProductPreviewController.cpp \
    backend/controllers/ProductSearchController.cpp \
    backend/controllers/UserSettingsController.cpp \
    backend/controllers/NVKController.cpp \
    backend/graphics_items/Category.cpp \
    backend/graphics_items/Product.cpp \
    backend/graphics_items/UserPanelItem.cpp \
    backend/network/HttpHandler.cpp \
    backend/network/JsonQuery.cpp \
    backend/network/JsonReply.cpp \
    backend/network/JsonRequest.cpp \
    backend/network/NetworkHandler.cpp \
    backend/scenes/CategoriesScene.cpp \
    backend/scenes/ProductsScene.cpp \
    backend/scenes/UserPanelScene.cpp \
    backend/Address.cpp \
    backend/Cart.cpp \
    backend/Order.cpp \
    backend/ProductSearch.cpp \
    backend/ProductProperty.cpp \
    backend/Property.cpp \
    backend/User.cpp \
    backend/UserProperty.cpp \
    frontend/views/CategoriesView.cpp \
    frontend/views/ProductsView.cpp \
    frontend/views/UserPanelView.cpp \
    frontend/widgets/ForgotUserDataWindow.cpp \
    frontend/widgets/LoginWindow.cpp \
    frontend/widgets/ManageOrderWindow.cpp \
    frontend/widgets/NVKMainWindow.cpp \
    frontend/widgets/PlaceOrderWindow.cpp \
    frontend/widgets/ProductPreviewDialog.cpp \
    frontend/widgets/UserSettingsWindow.cpp \
    frontend/widgets/ProductSearchWindow.cpp

HEADERS  += backend/controllers/ForgotUserDataController.h \
    backend/controllers/LoginController.h \
    backend/controllers/PlaceOrderController.h \
    backend/controllers/ManageOrderController.h \
    backend/controllers/ProductPreviewController.h \
    backend/controllers/ProductSearchController.h \
    backend/controllers/UserSettingsController.h \
    backend/controllers/NVKController.h \
    backend/graphics_items/Category.h \
    backend/graphics_items/Product.h \
    backend/graphics_items/UserPanelItem.h \
    backend/network/HttpHandler.h \
    backend/network/JsonQuery.h \
    backend/network/JsonReply.h \
    backend/network/JsonRequest.h \
    backend/network/NetworkHandler.h \
    backend/scenes/CategoriesScene.h \
    backend/scenes/ProductsScene.h \
    backend/scenes/UserPanelScene.h \
    backend/Address.h \
    backend/Cart.h \
    backend/Order.h \
    backend/ProductSearch.h \
    backend/ProductProperty.h \
    backend/Property.h \
    backend/User.h \
    backend/UserProperty.h \
    frontend/views/CategoriesView.h \
    frontend/views/ProductsView.h \
    frontend/views/UserPanelView.h \
    frontend/widgets/ForgotUserDataWindow.h \
    frontend/widgets/LoginWindow.h \
    frontend/widgets/ManageOrderWindow.h \
    frontend/widgets/NVKMainWindow.h \
    frontend/widgets/PlaceOrderWindow.h \
    frontend/widgets/ProductPreviewDialog.h \
    frontend/widgets/UserSettingsWindow.h \
    frontend/widgets/ProductSearchWindow.h

FORMS+= frontend/ui/forgotuserdatawindow.ui \
    frontend/ui/loginwindow.ui \
    frontend/ui/manageorderwindow.ui \
    frontend/ui/nvkmainwindow.ui \
    frontend/ui/placeorderwindow.ui \
    frontend/ui/productpreviewdialog.ui \
    frontend/ui/usersettingswindow.ui \
    frontend/ui/productsearchwindow.ui

CONFIG += mobility qt
CONFIG += C++11
RESOURCES += resources/images.qrc

 INCLUDEPATH += frontend \
    backend

DISTFILES += \
    android/AndroidManifest.xml \
    android/res/values/libs.xml \
    android/build.gradle

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
