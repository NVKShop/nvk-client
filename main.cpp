#include "backend/controllers/NVKController.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    NVKController controller;
    controller.loginWindow();

    return a.exec();
}
