#include "ForgotUserDataWindow.h"
#include "ui_forgotuserdatawindow.h"
#include <QShowEvent>
#include <QScreen>
ForgotUserDataWindow::ForgotUserDataWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ForgotUserDataWindow)
{
    ui->setupUi(this);

#ifdef Q_OS_ANDROID
    QScreen *screen = QApplication::screens().at(0);
    int w = screen->size().width();
    int h = screen->size().height();

    ui->gridLayout->setContentsMargins(w/4- ui->label->width(), h/3,
                                       w/4- ui->label->width(), h/3);
#endif

    QFont buttonFont = ui->cancelButton->font();

#ifdef Q_OS_ANDROID
    buttonFont.setPointSize(buttonFont.pointSize()/ 2);
#endif

    ui->cancelButton->setFont(buttonFont);
    ui->sendReminderButton->setFont(buttonFont);
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
