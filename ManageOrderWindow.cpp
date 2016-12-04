#include "ManageOrderWindow.h"
#include "ui_manageorderwindow.h"

ManageOrderWindow::ManageOrderWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageOrderWindow)
{
    ui->setupUi(this);
}

ManageOrderWindow::~ManageOrderWindow()
{
    delete ui;
}
