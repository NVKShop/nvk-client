#include "frontend/widgets/LoginWindow.h"
#include "ui_loginwindow.h"
#include "backend/network/NetworkHandler.h"

#include <QMessageBox>
#include <QScreen>
#include <QDesktopServices>
#include <QPalette>

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow),
    m_connected(false)
{
    ui->setupUi(this);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);

    ui->forgotUserNameLabel->setText("<a href=\"stuff\">Forgot username or password?</a>");
    ui->forgotUserNameLabel->setOpenExternalLinks(false);
    ui->forgotUserNameLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);

    ui->registerUserLabel->setText(tr("New user? <a href=\"http://google.com\">Register!<a/>"));
    ui->registerUserLabel->setOpenExternalLinks(true);
    ui->forgotUserNameLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);

    QPalette p(palette());
    setAutoFillBackground(true);
    p.setColor(QPalette::Background, QColor::fromRgb(0x42, 0x41, 0x3D));
    setPalette(p);

    QPalette pt(ui->label->palette());
    pt.setColor(QPalette::WindowText, QColor::fromRgb(0xFF, 0xCE,0x2B));
    ui->label->setPalette(pt);
    ui->label_2->setPalette(pt);
    ui->forgotUserNameLabel->setPalette(pt);
    ui->registerUserLabel->setPalette(pt);

#ifdef Q_OS_ANDROID
    QScreen *screen = QApplication::screens().at(0);
    int w = screen->size().width();
    int h = screen->size().height();

    ui->gridLayout->setContentsMargins(w/4 - ui->forgotUserNameLabel->width(), h/3,
                                       w/4- ui->forgotUserNameLabel->width(), h/3);
    ui->loginButton->resize(ui->loginButton->size()+ui->loginButton->size()/3);
    ui->cancelButton->resize(ui->cancelButton->size() + ui->cancelButton->size()/3);
#endif
    ui->loginButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                     "stop: 0 white, stop: 1 grey);"
                                                     "border-style: solid;"
                                                     "border-width: 2px;"
                                                     "border-color: black;"
                                                     "border-radius: 15px;}"));
    ui->cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                      "stop: 0 white, stop: 1 grey);"
                                                      "border-style: solid;"
                                                      "border-width: 2px;"
                                                      "border-color: black;"
                                                      "border-radius: 15px;}"));

    QFont nvkFont;

#ifdef Q_OS_ANDROID
    nvkFont.setPointSize(25);
#else
    nvkFont.setPointSize(30);
#endif
    ui->nvkShopLabel->setFont(nvkFont);
    ui->nvkShopLabel->adjustSize();

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

void LoginWindow::loginError(const QString &message)
{
    QMessageBox::warning(0, "Login error", "Error, " + message);
}

void LoginWindow::login()
{

    NetworkHandler networkHandler;

    if (networkHandler.isConnectedToTheInternet())
    {
        if (!m_connected)
        {
            m_connected = true;

            emit loginUser();
        }
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
