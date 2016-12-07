#include "frontend/widgets/UserSettingsWindow.h"
#include "ui_usersettingswindow.h"

UserSettingsWindow::UserSettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserSettingsWindow)
{
    ui->setupUi(this);

    connect(ui->cancelButton, &QPushButton::clicked, this, &UserSettingsWindow::close);
    connect(ui->saveSettingsButton, &QPushButton::clicked, this, &UserSettingsWindow::saveSettingsButtonClicked);
}

UserSettingsWindow::~UserSettingsWindow()
{
    delete ui;
}

void UserSettingsWindow::showEvent(QShowEvent *e)
{
#ifdef Q_OS_ANDROID
    showFullScreen();
#else
    show();
#endif
    QWidget::showEvent(e);
}
