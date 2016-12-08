#include "LoginController.h"

LoginController::LoginController(QObject *parent) : QObject(parent), m_loginWindow(new LoginWindow)
{
    connect(m_loginWindow, &LoginWindow::loginUser, this, &LoginController::loginUser);
    connect(this, &LoginController::loginError, m_loginWindow, &LoginWindow::loginError);
}

LoginWindow* LoginController::view() const
{
    return m_loginWindow;
}
#include<QDebug>
void LoginController::loginUser()
{
    //user authentication..
    // get json reply with user datas

    User* user = new User;
    UserProperty properties;

    properties.setName(m_loginWindow->userName());
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
        emit loginError("your username is banned!");
    }
    else
    {
        emit loginOk(user);
    }

    // if error..emit loginError(errorMsg)
}
