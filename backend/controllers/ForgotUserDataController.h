#ifndef FORGOTUSERDATACONTROLLER_H
#define FORGOTUSERDATACONTROLLER_H

#include "frontend/widgets/ForgotUserDataWindow.h"

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
    void serverReplyError(const int &);

private:
    ForgotUserDataWindow* m_forgotUserDataWindow;
};

#endif // FORGOTUSERDATACONTROLLER_H
