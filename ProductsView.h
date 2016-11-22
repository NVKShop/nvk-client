#ifndef PRODUCTSVIEW_H
#define PRODUCTSVIEW_H

#include <QGraphicsView>
#include "ProductsScene.h"
class ProductsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ProductsView(ProductsScene* scene, QWidget* parent);
    ProductsView(QWidget* parent);
};

#endif // PRODUCTSVIEW_H
