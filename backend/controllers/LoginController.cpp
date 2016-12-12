#include "LoginController.h"
#include <QMessageBox>
#include <QSettings>
#include <QDebug>

LoginController::LoginController(QObject *parent) : QObject(parent), m_loginWindow(new LoginWindow)
{
    connect(m_loginWindow, &LoginWindow::loginUser, this, &LoginController::loginUser);
    connect(this, &LoginController::loginError, m_loginWindow, &LoginWindow::loginError);
}

LoginWindow* LoginController::view() const
{
    return m_loginWindow;
}

void LoginController::loginUser()
{
    if (!view()->dataEntered())
    {
        emit loginError("you must enter your username and password!");
    }
    else
    {
        //user authentication..
        // get json reply with user datas

        User* user = new User;
        UserProperty properties;

        properties.setName(m_loginWindow->userName());
        properties.setPassword(m_loginWindow->userPassword());
        properties.setFirstName("Lakatos");
        properties.setLastName("Nintendó");
        properties.setPhoneNumber("06 372 3292");
        properties.setEmail("f/kristof@hotmail.com");
        properties.setRole(UserProperty::ROLE_USER);
        //    properties.setBanned(true);
        Address userAddress;
        userAddress.setCity("Debrecen");
        userAddress.setCountry("Hungary");
        userAddress.setZip("4027");
        userAddress.setHouseNumber("13");
        userAddress.setStreet("Egyetem sgt");

        properties.setAddress(userAddress);

        user->setProperties(properties);

        if (user->properties().isBanned())
        {
        }
        else
        {
            QSettings settings;
            settings.setValue("userName", properties.name());
            settings.setValue("password", properties.password());
            emit loginOk(user);
        }
        // if error..emit loginError(errorMsg)

    }
}
