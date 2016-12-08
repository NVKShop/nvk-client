#include "frontend/widgets/UserSettingsWindow.h"
#include "ui_usersettingswindow.h"
#include <QPalette>
#include <QColor>
#include <QLineEdit>

UserSettingsWindow::UserSettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserSettingsWindow)
{
    ui->setupUi(this);
    QPalette p(palette());
    setAutoFillBackground(true);
    p.setColor(QPalette::Background, QColor::fromRgb(0x42, 0x41, 0x3D));
    setPalette(p);
    /*connect(ui->addressCityLineEdit, &QLineEdit::textEdited, this, &UserSettingsWindow::addressCityChanged);
    connect(ui->emailLineEdit, &QLineEdit::textEdited, this, &UserSettingsWindow::emailChanged);
    connect(ui->firstNameLineEdit, &QLineEdit::textEdited, this, &UserSettingsWindow::firstNameChanged);

*/
    ui->cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
      "stop: 0 white, stop: 1 grey);"
      "border-style: solid;"
      "border-width: 2px;"
      "border-color: black;"
      "border-radius: 15px;}"));
    ui->saveSettingsButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
      "stop: 0 white, stop: 1 grey);"
      "border-style: solid;"
      "border-width: 2px;"
      "border-color: black;"
      "border-radius: 15px;}"));
    QPalette pt(ui->label->palette());
    pt.setColor(QPalette::WindowText, QColor::fromRgb(0xFF, 0xCE,0x2B));
    foreach (QObject* o, children()) {
        if (qobject_cast<QLabel*>(o))
        {
            qobject_cast<QLabel*>(o)->setPalette(pt);
        }
    }

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
#include <QDebug>
void UserSettingsWindow::setUser(User *user)
{
    const UserProperty& prop = user->properties();
    ui->userNameLineEdit->setText(prop.name());
    ui->emailLineEdit->setText(prop.email());
    ui->firstNameLineEdit->setText(prop.firstName());
    ui->lastNameLineEdit->setText(prop.lastName());
    ui->phoneNumberLineEdit->setText(prop.phoneNumber());
    const Address address = prop.address();
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

bool UserSettingsWindow::hasChanges() const
{
    return m_addressChanged || m_firstNameChanged ||
            m_lastNameChanged || m_phoneNumberChanged ||
            m_emailChanged;
}

bool UserSettingsWindow::emailChanged() const
{
    return m_emailChanged;
}

bool UserSettingsWindow::addressChanged() const
{
    return m_addressChanged;
}

bool UserSettingsWindow::firstNameChanged() const
{
    return m_firstNameChanged;
}

bool UserSettingsWindow::lastNameChanged() const
{
    return m_lastNameChanged;
}

bool UserSettingsWindow::phoneNumberChanged() const
{
    return m_phoneNumberChanged;
}

void UserSettingsWindow::addressChangedSomewhere()
{
    if (!m_addressChanged)
    {
        m_addressChanged = true;
    }
}

void UserSettingsWindow::firstNameTextChanged()
{
    if (!m_firstNameChanged)
    {
        m_firstNameChanged = true;
    }
}

void UserSettingsWindow::lastNameTextChanged()
{
    if (!m_lastNameChanged)
    {
        m_lastNameChanged = true;
    }
}

void UserSettingsWindow::phoneNumberTextChanged()
{
    if (!m_phoneNumberChanged)
    {
        m_phoneNumberChanged = true;
    }
}

void UserSettingsWindow::emailTextChanged()
{
    if (!m_emailChanged)
    {
        m_emailChanged = true;
    }
}
