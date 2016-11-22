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
    User();
    Cart* getCart();
signals:

public slots:

private:
    UserProperty m_Properties;
    Cart* m_Cart;

};

#endif // USER_H
