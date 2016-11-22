#ifndef CART_H
#define CART_H

#include <QVector>
#include "Product.h"

class Cart : public QObject
{
    Q_OBJECT
public:
    explicit Cart(const QVector<Product*>& products);
    Cart() = default;

    void addProduct(Product *product);
    bool removeProduct(Product *product);
signals:

public slots:

private:
    QVector<Product*> m_products;
};

#endif // CART_H
