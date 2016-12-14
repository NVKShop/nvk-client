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
    void setOrderTotalPrice(int total);
    int productsCount();
    int prodsCount() const;
    int orderTotalPrice() const;
signals:

public slots:
private:
    User* m_user;
    int m_orderProductsCount;
    double m_orderTotalPrice;
};

#endif // ORDER_H
