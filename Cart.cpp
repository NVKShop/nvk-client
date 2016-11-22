#include "Cart.h"

Cart::Cart(const QVector<Product*> &products) : m_products(products)
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
