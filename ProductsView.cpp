#include "ProductsView.h"

ProductsView::ProductsView(ProductsScene* scene, QWidget *parent) : QGraphicsView(scene,parent)
{
}

ProductsView::ProductsView(QWidget *parent) : QGraphicsView(parent)
{
}
