#ifndef FORGOTUSERDATACONTROLLER_H
#define FORGOTUSERDATACONTROLLER_H

#include "frontend/widgets/ForgotUserDataWindow.h"
#include "backend/network/HttpHandler.h"

#include <QObject>
#include <QNetworkReply>
class ForgotUserDataController : public QObject
{
    Q_OBJECT
public:
    explicit ForgotUserDataController(QObject *parent = 0);
    ForgotUserDataWindow* view() const;
    ~ForgotUserDataController();
Q_SIGNALS:
    void successfulReminder();
private Q_SLOTS:
    void forgotUserData(const QString &email);
    void unsuccessfulReminder(const int& code);
private:
    ForgotUserDataWindow* m_forgotUserDataWindow;
    HttpHandler* m_httpHandler;

};

#endif // FORGOTUSERDATACONTROLLER_H
