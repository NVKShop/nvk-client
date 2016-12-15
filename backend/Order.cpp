#include "backend/Order.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

Order::Order(User *user, QObject *parent) :  QObject(parent), m_user(user), m_orderProductsCount(0),
    m_orderTotalPrice(0.0)
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

void Order::setOrderTotalPrice(int total)
{
    m_orderTotalPrice = total;
}

int Order::orderTotalPrice() const
{
    return m_orderTotalPrice;
}

int Order::productsCount()
{
    int total = 0;
    foreach (Product* prod, m_user->cart()->products())
    {
        total+= prod->quantityInCart();
    }
    m_orderProductsCount = total;
    return total;
}

int Order::prodsCount() const
{
    return m_orderProductsCount;
}

QJsonDocument Order::asJson() const
{
    QJsonDocument doc;
    QJsonObject mainObj;

    QJsonArray products;
    foreach (Product* p, m_user->cart()->products()) {
        products.append(p->asJson());
    }
    mainObj["user"] = m_user->asJson();
    mainObj["products"] = products;
    return doc;
}
