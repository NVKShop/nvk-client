#include "NVKController.h"
#include <QMessageBox>
#include <QRegularExpression>

NVKController::NVKController(QObject *parent) : QObject(parent), m_loginWindow(new LoginWindow),
    m_forgotUserDataWindow(new ForgotUserDataWindow),
    m_mainWindow(new NVKMainWindow),
    m_placeOrderWindow(new PlaceOrderWindow)
{

    connect(m_loginWindow, &LoginWindow::showForgotUserWindow, m_forgotUserDataWindow, &ForgotUserDataWindow::show);
    connect(m_loginWindow, &LoginWindow::loginUser, this, &NVKController::loginUser);
    connect(m_forgotUserDataWindow, &ForgotUserDataWindow::forgotUserDataSent, this, &NVKController::forgotUserData);

    connect(m_loginWindow, &LoginWindow::rejected, this, &NVKController::loginCancelled);
    connect(m_mainWindow, &NVKMainWindow::closing, this, &NVKController::mainClosing);
    m_loginWindow->show();
    m_activeWindow = m_loginWindow;
}

void NVKController::changeActiveWindow(QWidget *window)
{
    window->show();

    if (m_activeWindow != nullptr) {
        m_activeWindow->hide();
    }
    m_activeWindow = window;

}

void NVKController::loginUser()
{
    User* user = new User;
    UserProperty properties;

    user->setProperties(properties);

    //check user..
    m_mainWindow->order()->setUser(user);
    changeActiveWindow(m_mainWindow);
}

void NVKController::placeOrder(Order *order)
{
    m_placeOrderWindow->setOrder(order);
    changeActiveWindow(m_placeOrderWindow);
}

void NVKController::loginCancelled()
{

}

void NVKController::forgotUserData(const QString &email)
{
    QRegularExpression rex("(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\\.[a-z0-9!#$%&'*+/=?^_`{|}~-"
                "]+)*|\"(?:[\\x01-\\x08\\x0b\\x0c\\x0e-"
                "\\x1f\\x21\\x23-\\x5b\\x5d-\\x7f]|\\\\[\\x01-"
                "\\x09\\x0b\\x0c\\x0e-\\x7f])*\")"
                "@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9]"
                ")?|\\[(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.)"
                "{3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?|[a-z0-9-]*"
                "[a-z0-9]:"
                "(?:[\\x01-\\x08\\x0b\\x0c\\x0e-\\x1f\\x21-\\x5a\\x53-\\x7f]"
                "|\\\\[\\x01-\\x09\\x0b\\x0c\\x0e-\\x7f])+)\\])");

    QRegularExpressionMatch match = rex.match(email);

    if (!email.isEmpty())
    {
        if (!match.hasMatch())
        {
            QMessageBox::warning(0, "Enter a valid address", "Error, email address is invalid");
        }
        else
        {
            // ok, network..
        }
    }
    else
    {
        QMessageBox::warning(0, "Enter an email address", "Error, email address is empty!");
    }
}

void NVKController::mainClosing()
{
    delete m_forgotUserDataWindow;
    delete m_loginWindow;
    delete m_placeOrderWindow;
}
