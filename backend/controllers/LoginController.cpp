#include "LoginController.h"
#include <QMessageBox>
#include <QJsonParseError>
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
        QUrl url = HttpHandler::USER_LOGIN_INFORMATIONS_QUERY_URL_STRING;
        m_loginHandler->setUrl(url);
        m_loginHandler->setUser(view()->userName());
        m_loginHandler->setPassword(view()->userPassword());

        m_loginHandler->sendRequest(QByteArray());
    }
}

void LoginController::emitLoginError()
{
    QString msg = m_loginHandler->reply()->errorString();
    emit loginError(msg);
}

void LoginController::loginFinished()
{
    QString r = QString::fromUtf8(m_loginHandler->reply()->readAll());
    JsonReply reply(QJsonDocument::fromJson(r.toUtf8()));

    User* u = reply.user();
    u->setUserName(view()->userName());
    u->setPassword(view()->userPassword());
    QSettings settings;
    settings.setValue("userName", view()->userName());
    settings.setValue("password", view()->userPassword());
    emit loginOk(u);
}
