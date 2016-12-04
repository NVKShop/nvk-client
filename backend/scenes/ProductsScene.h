#ifndef PRODUCTSSCENE_H
#define PRODUCTSSCENE_H

#include <QGraphicsScene>
#include "backend/graphics_items/Product.h"

class ProductsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    ProductsScene(const int viewWidth);
    void setItems(const QVector<Product*>& products);
private:
    int m_viewWidth;
protected:
    bool event(QEvent *event);

};

#endif // PRODUCTSSCENE_H
