#ifndef PRODUCTSVIEW_H
#define PRODUCTSVIEW_H

#include <QGraphicsView>
#include "backend/scenes/ProductsScene.h"
class QSwipeGesture;
class QPanGesture;
class QTapAndHoldGesture;

class ProductsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ProductsView(ProductsScene* scene, QWidget* parent);
    ProductsView(QWidget* parent);
    void scrollToTop();

protected:
    void mouseMoveEvent(QMouseEvent* e) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent* e) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

    bool viewportEvent(QEvent *event) Q_DECL_OVERRIDE;
    bool event(QEvent *event) Q_DECL_OVERRIDE;
private:
    bool m_mouseDown = false;

    bool handleSwipe(QSwipeGesture* gesture);
    bool handleTapAndHold(QTapAndHoldGesture* gesture);

};

#endif // PRODUCTSVIEW_H
