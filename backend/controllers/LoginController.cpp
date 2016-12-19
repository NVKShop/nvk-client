#include "LoginController.h"
#include <QMessageBox>
#include <QSettings>
#include <QDebug>

LoginController::LoginController(QObject *parent) : QObject(parent), m_loginWindow(new LoginWindow),
    m_loginHandler(new HttpHandler)
{
    connect(m_loginWindow, &LoginWindow::loginUser, this, &LoginController::loginUser);
    connect(this, &LoginController::loginError, m_loginWindow, &LoginWindow::loginError);
    connect(m_loginHandler, &HttpHandler::replyErrors, this, &LoginController::emitLoginError);
    connect(m_loginHandler, &HttpHandler::finished, this, &LoginController::loginFinished);
}

LoginWindow* LoginController::view() const
{
    return m_loginWindow;
}

LoginController::~LoginController()
{
    delete m_loginWindow;
}

void LoginController::loginUser()
{
    if (!view()->dataEntered())
    {
        emit loginError("you must enter your username and password!");
    }
    else
    {
        //  NEW
        QUrl url = HttpHandler::USER_LOGIN_INFORMATIONS_QUERY_URL_STRING;
        m_loginHandler->setUrl(url);
        m_loginHandler->setUser(view()->userName());
        m_loginHandler->setPassword(view()->userPassword());

        m_loginHandler->sendRequest(QString());
    }
}

void LoginController::emitLoginError()
{
    QString msg = m_loginHandler->reply()->errorString();
    emit loginError(msg);
}

void LoginController::loginFinished()
{
    User* user = new User;
    UserProperty properties;

    Address userAddress;
    userAddress.setCity("Debrecen");
    userAddress.setCountry("Hungary");
    userAddress.setZip("4027");
    userAddress.setHouseNumber("13");
    userAddress.setStreet("Egyetem sgt");

    properties.setAddress(userAddress);

    properties.setName(m_loginWindow->userName());
    properties.setPassword(m_loginWindow->userPassword());
    properties.setFirstName("Lakatos");
    properties.setLastName("Nintendó");
    properties.setPhoneNumber("0063723292");
    properties.setEmail("f/kristof@hotmail.com");
    properties.setRole(UserProperty::ROLE_USER);

    user->setProperties(properties);

    QSettings settings;
    settings.setValue("userName", properties.name());
    settings.setValue("password", properties.password());
    emit loginOk(user);
}
