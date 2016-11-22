#ifndef PRODUCTSSCENE_H
#define PRODUCTSSCENE_H

#include <QGraphicsScene>
#include "Product.h"

class ProductsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    ProductsScene(const QRectF& sceneRect);
    void setItems(const QVector<Product*>& products);
};

#endif // PRODUCTSSCENE_H
