#include "backend/User.h"

User::User(const UserProperty &properties) : QObject(0),
    m_properties(properties), m_cart(new Cart())
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
