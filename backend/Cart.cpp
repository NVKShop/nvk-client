#include "backend/Cart.h"

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
