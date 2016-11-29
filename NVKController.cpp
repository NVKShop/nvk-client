#include "NVKController.h"

NVKController::NVKController(QObject *parent) : QObject(parent), m_loginWindow(new LoginWindow),
    m_forgotUserDataWindow(new ForgotUserDataWindow),
    m_mainWindow(new NVKMainWindow),
    m_placeOrderWindow(new PlaceOrderWindow)
{

    connect(m_loginWindow, &LoginWindow::showForgotUserWindow, m_forgotUserDataWindow, &ForgotUserDataWindow::show);
    connect(m_loginWindow, &LoginWindow::loginUser, this, &NVKController::loginUser);

    m_loginWindow->show();
}

void NVKController::changeActiveWindow(QWidget *window)
{
    if (m_activeWindow != nullptr) {
        m_activeWindow->hide();
    }
    m_activeWindow = window;
    m_activeWindow->show();
}

void NVKController::loginUser(User *user)
{
    m_mainWindow->order()->setUser(user);
    changeActiveWindow(m_mainWindow);
}

