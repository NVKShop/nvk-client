#include "ForgotUserDataWindow.h"
#include "ui_forgotuserdatawindow.h"

ForgotUserDataWindow::ForgotUserDataWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ForgotUserDataWindow)
{
    ui->setupUi(this);
}

ForgotUserDataWindow::~ForgotUserDataWindow()
{
    delete ui;
}
