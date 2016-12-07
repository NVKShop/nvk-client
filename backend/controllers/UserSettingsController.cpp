#include "UserSettingsController.h"
#include <QMessageBox>

UserSettingsController::UserSettingsController(QObject *parent) : QObject(parent),
    m_userSettingsWindow(new UserSettingsWindow)
{
    connect(m_userSettingsWindow, &UserSettingsWindow::saveSettingsButtonClicked, this, &UserSettingsController::saveSettings);
}

UserSettingsController::~UserSettingsController()
{
    delete m_userSettingsWindow;
}

UserSettingsWindow* UserSettingsController::view() const
{
    return m_userSettingsWindow;
}

void UserSettingsController::saveSettings()
{
    if (m_userSettingsWindow->emailSet())
    {
        //just do it/ check if sent
    }
    else
    {
        QMessageBox::warning(0, "Error", "E-mail address must be set!");
    }
}

void UserSettingsController::setUser(User* user)
{
    m_userSettingsWindow->setUser(user);
}
