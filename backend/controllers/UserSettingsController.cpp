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
        if (m_userSettingsWindow->hasChanges())
        {
            if (m_userSettingsWindow->emailChanged())
            {

            }
            if (m_userSettingsWindow->firstNameChanged())
            {

            }
            if (m_userSettingsWindow->lastNameChanged())
            {

            }
            if (m_userSettingsWindow->addressChanged())
            {

            }
            if (m_userSettingsWindow->phoneNumberChanged())
            {

            }
        }
    }
    else
    {
        QMessageBox::warning(0, "Error", "E-mail address must be set!");
    }
}

void UserSettingsController::setUser(User* user)
{
    m_user = user;
    m_userSettingsWindow->setUser(user);
}
