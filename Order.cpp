#include "Order.h"

Order::Order(User *user, QObject *parent) : m_user(user), QObject(parent)
{
}
