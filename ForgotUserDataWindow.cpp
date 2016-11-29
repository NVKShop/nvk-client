#include "ForgotUserDataWindow.h"
#include "ui_forgotuserdatawindow.h"
#include <QShowEvent>

ForgotUserDataWindow::ForgotUserDataWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ForgotUserDataWindow)
{
    ui->setupUi(this);

#ifdef Q_OS_ANDROID
    QScreen *screen = QApplication::screens().at(0);
    int w = screen->size().width();
    int h = screen->size().height();

    ui->gridLayout->setContentsMargins(w/4, h/3, w/4, h/3);
#endif
    connect(ui->sendReminderButton, &QPushButton::clicked, this, &ForgotUserDataWindow::forgotUserDataClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &ForgotUserDataWindow::close);
}

ForgotUserDataWindow::~ForgotUserDataWindow()
{
    delete ui;
}

void ForgotUserDataWindow::forgotUserDataClicked()
{
    emit forgotUserDataSent(ui->emailAddressLineEdit->text());
}

void ForgotUserDataWindow::showEvent(QShowEvent *e)
{
#ifdef Q_OS_ANDROID
    showFullScreen();
#else
    show();
#endif
    QDialog::showEvent(e);
}
