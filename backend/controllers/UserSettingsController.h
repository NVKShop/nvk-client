#ifndef USERSETTINGSCONTROLLER_H
#define USERSETTINGSCONTROLLER_H

#include "frontend/widgets/UserSettingsWindow.h"

#include <QObject>

class UserSettingsController : public QObject
{
    Q_OBJECT
public:
    explicit UserSettingsController(QObject *parent = 0);
    ~UserSettingsController();
Q_SIGNALS:

public Q_SLOTS:

private:
    UserSettingsWindow* m_userSettingsWindow;
};

#endif // USERSETTINGSCONTROLLER_H
