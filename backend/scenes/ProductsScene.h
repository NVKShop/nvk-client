#ifndef PRODUCTSSCENE_H
#define PRODUCTSSCENE_H

#include <QGraphicsScene>
#include "backend/graphics_items/Product.h"

class ProductsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    ProductsScene(const int viewWidth);
    ~ProductsScene();
    void setItems(const QVector<Product *> &products);
    bool isProductOnPosition();
private:
    int m_viewWidth;
protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
Q_SIGNALS:
    void productDoubleClicked(Product* product);
    void scrollToTop();
private:
    QGraphicsPixmapItem* m_scrollToTopItem;

};

#endif // PRODUCTSSCENE_H
