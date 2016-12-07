#ifndef ORDER_H
#define ORDER_H

#include <QObject>
#include "backend/User.h"

class Order : public QObject
{
    Q_OBJECT
public:
    explicit Order(User *user, QObject *parent = 0);
    Order() = default;
    void setUser(User* user);
    User* user() const;
signals:

public slots:
private:
    User* m_user;
};

#endif // ORDER_H
