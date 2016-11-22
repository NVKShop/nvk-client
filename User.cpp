#include "User.h"

User::User(const UserProperty &properties) : m_Properties(properties), m_Cart(new Cart())
{
}

User::User()
{
}

Cart* User::getCart()
{
    return m_Cart;
}
