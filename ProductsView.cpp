#include "ProductsView.h"
#include <QMouseEvent>
#include <QTouchEvent>
#include <QGestureEvent>
#include <QSwipeGesture>
#include <QPanGesture>
#include <QTapAndHoldGesture>
#include <QScrollBar>

#include <QDebug>

ProductsView::ProductsView(ProductsScene* scene, QWidget *parent) : QGraphicsView(scene,parent)
{
}

ProductsView::ProductsView(QWidget *parent) : QGraphicsView(parent)
{
    setInteractive(true);

    grabGesture(Qt::SwipeGesture);
    grabGesture(Qt::PanGesture);
    viewport()->grabGesture(Qt::SwipeGesture);
    viewport()->grabGesture(Qt::PanGesture);
    QGraphicsView::setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
}

void ProductsView::mouseMoveEvent(QMouseEvent *e)
{
    QGraphicsView::mouseMoveEvent(e);
}

void ProductsView::mousePressEvent(QMouseEvent *e)
{
#ifndef Q_OS_ANDROID
    setDragMode(QGraphicsView::ScrollHandDrag);
#endif
    QGraphicsView::mousePressEvent(e);
}

void ProductsView::mouseReleaseEvent(QMouseEvent *e)
{
#ifndef Q_OS_ANDROID
    setDragMode(QGraphicsView::NoDrag);
#endif
    QGraphicsView::mouseReleaseEvent(e);
}

bool ProductsView::viewportEvent(QEvent *event)
{
    if (event->type() == QEvent::Gesture)
    {
        QGestureEvent* e = static_cast<QGestureEvent*>(event);

        if (QGesture* swipe = e->gesture(Qt::SwipeGesture))
        {
            return handleSwipe(static_cast<QSwipeGesture*>(swipe));
        }
        if (QGesture* pan = e->gesture(Qt::PanGesture))
        {
            return handlePan(static_cast<QPanGesture*>(pan));
        }
        if (QGesture* taphold = e->gesture(Qt::TapAndHoldGesture))
        {
            return handleTapAndHold(static_cast<QTapAndHoldGesture*>(taphold));

        }
    }
    return QGraphicsView::viewportEvent(event);
}

bool ProductsView::event(QEvent *event)
{
    return QGraphicsView::event(event);
}

bool ProductsView::handleSwipe(QSwipeGesture *gesture)
{
    if (gesture->state() == Qt::GestureFinished)
    {
        QScrollBar* vbar = verticalScrollBar();

        if (gesture->verticalDirection() == QSwipeGesture::Up)
        {
            vbar->setValue(vbar->value() - 10);
        }
        else if (gesture->verticalDirection() == QSwipeGesture::Down)
        {
            vbar->setValue(vbar->value() + 10);
        }
        qDebug() << "swipe";
    }

    return true;
}

bool ProductsView::handlePan(QPanGesture *gesture)
{
    QScrollBar* vbar = verticalScrollBar();

    vbar->setValue(vbar->value() + gesture->delta().y());
    qDebug() << "pan";

    return true;
}

bool ProductsView::handleTapAndHold(QTapAndHoldGesture *gesture)
{
    qDebug() << "taphold";
    return true;
}


