#include "backend/User.h"
#include <QJsonObject>
#include <QJsonValue>

User::User(const UserProperty &properties) : QObject(0),
    m_properties(properties), m_cart(new Cart())
{
}

User::User() : m_cart(new Cart)
{
}

Cart* User::cart() const
{
    return m_cart;
}

UserProperty User::properties() const
{
    return m_properties;
}

void User::setCart(Cart *cart)
{
    this->m_cart = cart;
}

void User::setProperties(const UserProperty &properties)
{
    this->m_properties = properties;
}

QJsonObject User::asJson() const
{
    QJsonObject user;

    QJsonValue juserName = m_properties.name();
    QJsonValue juserId = static_cast<int>(m_properties.id());
    user["name"] = juserName;
    user["id"] = juserId;
    user["address"] = m_properties.address().asJson();
    return user;
}
