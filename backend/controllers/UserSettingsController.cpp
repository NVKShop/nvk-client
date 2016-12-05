#include "UserSettingsController.h"

UserSettingsController::UserSettingsController(QObject *parent) : QObject(parent),
    m_userSettingsWindow(new UserSettingsWindow)
{

}
