#include "NVKMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NVKMainWindow w;
    w.show();

    return a.exec();
}
