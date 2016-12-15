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
    ProductsView(QWidget* parent = 0);
    ~ProductsView();
protected:
    void mouseMoveEvent(QMouseEvent* e) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent* e) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

    void resizeEvent(QResizeEvent* event) Q_DECL_OVERRIDE;
    bool viewportEvent(QEvent *event) Q_DECL_OVERRIDE;
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    void showEvent(QShowEvent *event) Q_DECL_OVERRIDE;
private:
    int m_currentPage;
    QMenu* m_addToCartMenu;
    QAction* m_addToCartAction;
    bool handleSwipe(QSwipeGesture* gesture);
    bool handleTapAndHold(QTapAndHoldGesture* gesture);
public Q_SLOTS:
    void scrollToTop();
    void emitAddToCartActionTriggered();
Q_SIGNALS:
    void addToCartActionTriggered(Product* pprod);

};

#endif // PRODUCTSVIEW_H
