#include "PlaceOrderWindow.h"
#include "ui_placeorderwindow.h"

PlaceOrderWindow::PlaceOrderWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlaceOrderWindow)
{
    ui->setupUi(this);
}

PlaceOrderWindow::~PlaceOrderWindow()
{
    delete ui;
}
