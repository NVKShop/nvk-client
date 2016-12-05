#ifndef FORGOTUSERDATACONTROLLER_H
#define FORGOTUSERDATACONTROLLER_H

#include "frontend/widgets/ForgotUserDataWindow.h"

#include <QObject>

class ForgotUserDataController : public QObject
{
    Q_OBJECT
public:
    explicit ForgotUserDataController(QObject *parent = 0);
    ForgotUserDataWindow* view() const;
Q_SIGNALS:
    void successfulReminder();
private Q_SLOTS:
    void forgotUserData(const QString &email);

private:
    ForgotUserDataWindow* m_forgotUserDataWindow;

};

#endif // FORGOTUSERDATACONTROLLER_H
