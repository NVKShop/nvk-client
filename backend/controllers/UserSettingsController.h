#ifndef USERSETTINGSCONTROLLER_H
#define USERSETTINGSCONTROLLER_H

#include <QObject>

class UserSettingsController : public QObject
{
    Q_OBJECT
public:
    explicit UserSettingsController(QObject *parent = 0);

signals:

public slots:
};

#endif // USERSETTINGSCONTROLLER_H