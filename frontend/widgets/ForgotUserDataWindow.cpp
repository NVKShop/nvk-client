#include "frontend/widgets/ForgotUserDataWindow.h"
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

    ui->gridLayout->setContentsMargins(w/6- ui->label->width(), h/3,
                                       w/6- ui->label->width(), h/3);
#endif

    QFont buttonFont = ui->cancelButton->font();

#ifdef Q_OS_ANDROID
    buttonFont.setPointSize(buttonFont.pointSize()/ 2);
#endif

    ui->cancelButton->setFont(buttonFont);
    ui->sendReminderButton->setFont(buttonFont);
    connect(ui->sendReminderButton, &QPushButton::clicked, this, &ForgotUserDataWindow::forgotUserDataClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &ForgotUserDataWindow::close);

    ui->cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
      "stop: 0 white, stop: 1 grey);"
      "border-style: solid;"
      "border-width: 2px;"
      "border-color: black;"
      "border-radius: 15px;}"));

    ui->sendReminderButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
      "stop: 0 white, stop: 1 grey);"
      "border-style: solid;"
      "border-width: 2px;"
      "border-color: black;"
      "border-radius: 15px;}"));
    QPalette pt(ui->label->palette());
    pt.setColor(QPalette::WindowText, QColor::fromRgb(0xFF, 0xCE,0x2B));
    ui->label->setPalette(pt);

    QPalette p(palette());
    setAutoFillBackground(true);
    p.setColor(QPalette::Background, QColor::fromRgb(0x42, 0x41, 0x3D));
    setPalette(p);
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
