#ifndef CART_H
#define CART_H

#include <QVector>
#include "Product.h"

class Cart : public QObject
{
    Q_OBJECT
public:
    Cart() = default;

    void addProduct(Product *product);
    void addProducts(const QVector<Product*>& products);
    bool removeProduct(Product *product);
signals:

public slots:

private:
    QVector<Product*> m_products;
};

#endif // CART_H
