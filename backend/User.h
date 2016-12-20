#ifndef USER_H
#define USER_H

#include <QObject>
#include "backend/UserProperty.h"
#include "backend/Cart.h"

class Cart;
class User : public QObject
{
    Q_OBJECT
public:
    explicit User(const UserProperty& properties);
    User() ;
    Cart *cart() const;
    UserProperty properties() const;
    void setCart(Cart *cart);
    void setUserName(const QString& userName);
    void setPassword(const QString& pw);
    void setProperties(const UserProperty& properties);
    QJsonObject asJson() const;
signals:

public slots:

private:
    UserProperty m_properties;
    Cart* m_cart;

};

#endif // USER_H
