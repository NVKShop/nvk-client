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
protected:
    void mouseMoveEvent(QMouseEvent* e) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent* e) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

    bool viewportEvent(QEvent *event) Q_DECL_OVERRIDE;

private:
    bool m_mouseDown = false;
    qreal m_mouseDownPosY;
};

#endif // PRODUCTSVIEW_H
