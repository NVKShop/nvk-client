#include "LoginWindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);

    connect(ui->forgotUserNameLabel, &QLabel::linkActivated, this, &LoginWindow::forgotUserNameClicked);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::forgotUserNameClicked(const QString &)
{
    //show forgot username dialog
}
