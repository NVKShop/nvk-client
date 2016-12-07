#include "UserSettingsController.h"

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
    //save shit
}
