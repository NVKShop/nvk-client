#include "backend/Cart.h"
#include <QDebug>

Cart::Cart()
{
}

void Cart::addProduct(Product* product)
{
    if (!m_products.contains(product))
    {
        m_products.push_back(product);
    }
}

bool Cart::removeProduct(Product* product)
{
    for (int i = 0; i < m_products.size(); ++i)
    {
        Product* p = m_products[i];
        if (p->properties().id() == product->properties().id())
        {
            p->setQuantity(0);
            m_products.remove(i);
            return true;
        }
    }
    return false;
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
    qDeleteAll(m_products);
    m_products.resize(0);
}
