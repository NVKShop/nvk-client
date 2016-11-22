#ifndef USER_H
#define USER_H

#include <QObject>
#include "UserProperty.h"
#include "Cart.h"

class Cart;
class User : public QObject
{
    Q_OBJECT
public:
    explicit User(const UserProperty& properties);
    User() = default;
    Cart *cart() const;
    UserProperty properties() const;
    void setCart(Cart *cart);
    void setProperties(const UserProperty& properties);
signals:

public slots:

private:
    UserProperty m_properties;
    Cart* m_cart;

};

#endif // USER_H
