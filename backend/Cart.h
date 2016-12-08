#ifndef CART_H
#define CART_H

#include <QVector>
#include "backend/graphics_items/Product.h"

class Cart : public QObject
{
    Q_OBJECT
public:
    Cart();

    void addProduct(Product *product);
    void addProducts(const QVector<Product*>& products);
    bool removeProduct(Product *product);
    QVector<Product*> products() const;

signals:

public slots:

private:
    QVector<Product*> m_products;
};

#endif // CART_H
