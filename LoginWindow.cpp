#include "LoginWindow.h"
#include "ui_loginwindow.h"
#include "NetworkHandler.h"

#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);

    connect(ui->loginButton, &QPushButton::clicked, this, &LoginWindow::login);
    connect(ui->forgotUserNameLabel, &QLabel::linkActivated, this, &LoginWindow::forgotUserNameClicked);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::forgotUserNameClicked()
{
    emit forgotUserNameClicked();
}

void LoginWindow::login()
{
    if (NetworkHandler::isConnectedToTheInternet())
    {
        // check user.., controller -> showmain
        User* user = new User();
        UserProperty uprop;
        uprop.setName(ui->userNameEdit->text());

        emit loginUser(user);
    }
    else
    {
        QMessageBox::warning(0, "Connection error", "Error, no internet connection");
    }
}
