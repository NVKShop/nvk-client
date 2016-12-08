#include "backend/Cart.h"
#include <QDebug>

Cart::Cart()
{
}

void Cart::addProduct(Product* product)
{
    m_products.push_back(product);
}

bool Cart::removeProduct(Product* product)
{
    return m_products.removeOne(product);
}

void Cart::addProducts(const QVector<Product *> &products)
{
    foreach (Product* p, products) {
        m_products.push_back(p);
    }
}

QVector<Product*> Cart::products() const
{
    return m_products;
}

void Cart::resetCart()
{
    foreach (Product* prod, m_products) {
        prod->removedFromCart();
    }
    m_products.clear();
    m_products.resize(0);
}
