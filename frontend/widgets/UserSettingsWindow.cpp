#include "frontend/widgets/UserSettingsWindow.h"
#include "ui_usersettingswindow.h"
#include <QPalette>
#include <QColor>

UserSettingsWindow::UserSettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserSettingsWindow)
{
    ui->setupUi(this);
    QPalette p(palette());
    setAutoFillBackground(true);
    p.setColor(QPalette::Background, QColor::fromRgb(0x42, 0x41, 0x3D));
    setPalette(p);

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

void UserSettingsWindow::setUser(User *user)
{
    const UserProperty& prop = user->properties();
    ui->userNameLineEdit->setText(prop.name());
    ui->emailLineEdit->setText(prop.email());
    ui->firstNameLineEdit->setText(prop.firstName());
    ui->lastNameLineEdit->setText(prop.lastName());
    const Address& address = prop.address();
    ui->addressCountryLineEdit->setText(address.country());
    ui->addressCityLineEdit->setText(address.city());
    ui->addressHouseNumberLineEdit->setText(address.houseNumber());
    ui->addressStreetLineEdit->setText(address.street());
    ui->addressZipLineEdit->setText(address.zip());
}

bool UserSettingsWindow::emailSet() const
{
    return ui->emailLineEdit->text().isEmpty();
}
