#ifndef PRODUCTSSCENE_H
#define PRODUCTSSCENE_H

#include <QGraphicsScene>
#include "Product.h"

class ProductsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    ProductsScene(const int viewWidth);
    void setItems(const QVector<Product*>& products);
private:
    int m_viewWidth;
};

#endif // PRODUCTSSCENE_H
