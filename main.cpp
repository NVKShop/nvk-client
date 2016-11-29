#include "NVKMainWindow.h"
#include "NVKController.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*NVKMainWindow w;
    w.show();*/

    NVKController controller;

    return a.exec();
}
