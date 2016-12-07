#include "backend/Order.h"

Order::Order(User *user, QObject *parent) :  QObject(parent), m_user(user)
{
}

void Order::setUser(User *user)
{
    m_user = user;
}

User* Order::user() const
{
    return m_user;
}
