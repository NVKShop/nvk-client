#include "LoginWindow.h"
#include "ui_loginwindow.h"
#include "NetworkHandler.h"

#include <QMessageBox>
#include <QScreen>

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);

    ui->forgotUserNameLabel->setText("<a href=\"stuff\">Forgot username or password?</a>");
    ui->forgotUserNameLabel->setOpenExternalLinks(false);
    ui->forgotUserNameLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);

#ifdef Q_OS_ANDROID
    QScreen *screen = QApplication::screens().at(0);
    int w = screen->size().width();
    int h = screen->size().height();

    ui->gridLayout->setContentsMargins(w/4 - ui->forgotUserNameLabel->width(), h/3,
                                       w/4- ui->forgotUserNameLabel->width(), h/3);
#endif

    connect(ui->loginButton, &QPushButton::clicked, this, &LoginWindow::login);
    connect(ui->forgotUserNameLabel, &QLabel::linkActivated, this, &LoginWindow::forgotUserNameClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &LoginWindow::reject);

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::forgotUserNameClicked()
{
    emit showForgotUserWindow();
}

void LoginWindow::login()
{
    if (NetworkHandler::isConnectedToTheInternet())
    {
        qDebug() << "Connected to internet..";
        emit loginUser();
    }
    else
    {
        QMessageBox::warning(0, "Connection error", "Error, no internet connection");
    }
}

void LoginWindow::showEvent(QShowEvent *e)
{
#ifdef Q_OS_ANDROID
    showFullScreen();
#else
    show();
#endif
    QDialog::showEvent(e);
}

QString LoginWindow::userName() const
{
    return ui->userNameEdit->text();
}

QString LoginWindow::userPassword() const
{
    return ui->passwordEdit->text();
}
