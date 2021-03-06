#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include "frontend/widgets/LoginWindow.h"
#include "backend/network/HttpHandler.h"
#include <QObject>

class LoginController : public QObject
{
    Q_OBJECT
public:
    explicit LoginController(QObject *parent = 0);
    LoginWindow* view() const;
    ~LoginController();
Q_SIGNALS:
    void showForgotUserWindow();
    void loginOk(User* user);
    void loginError(const QString& message);
public Q_SLOTS:

private Q_SLOTS:
    void loginUser();
    void loginFinished();
    void emitLoginError();
private:
    LoginWindow* m_loginWindow;
    HttpHandler* m_loginHandler;
};

#endif // LOGINCONTROLLER_H
