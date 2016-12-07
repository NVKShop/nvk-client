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

void LoginController::loginUser()
{
    //user authentication..
    // get json reply with user datas

    User* user = new User;
    UserProperty properties;

    properties.setName(m_loginWindow->userName());

    Address userAddress;
    userAddress.setCity("Debrecen");
    userAddress.setCountry("Hungary");
    userAddress.setZip("4027");
    userAddress.setHouseNumber("13");
    userAddress.setStreet("Egyetem sgt");

    properties.setAddress(userAddress);
    user->setProperties(properties);
    emit loginOk(user);

    // if error..emit loginError(errorMsg)
}
