#include "UserSettingsController.h"

UserSettingsController::UserSettingsController(QObject *parent) : QObject(parent),
    m_userSettingsWindow(new UserSettingsWindow)
{

}

UserSettingsController::~UserSettingsController()
{
    delete m_userSettingsWindow;
}
