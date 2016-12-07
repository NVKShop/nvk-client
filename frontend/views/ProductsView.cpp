#include "frontend/views/ProductsView.h"
#include <QMouseEvent>
#include <QTouchEvent>
#include <QGestureEvent>
#include <QSwipeGesture>
#include <QPanGesture>
#include <QTapAndHoldGesture>
#include <QScrollBar>
#include <QScroller>
#include <QMenu>
#include <QAction>
#include <QResizeEvent>
#include <QSize>

#include <QDebug>

ProductsView::ProductsView(QWidget *parent) : QGraphicsView(parent)
{
    setInteractive(true);

    grabGesture(Qt::SwipeGesture);
    grabGesture(Qt::PanGesture);
    viewport()->grabGesture(Qt::SwipeGesture);
    grabGesture(Qt::TapAndHoldGesture);
    viewport()->grabGesture(Qt::TapAndHoldGesture);
#ifdef Q_OS_ANDROID
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
#endif

    m_addToCartMenu = new QMenu;

    m_addToCartAction = new QAction(QIcon(QPixmap(":/images/addToCartAction.png")),"Add to cart");
    m_addToCartMenu->addAction(m_addToCartAction);

    connect(m_addToCartAction, &QAction::triggered, this, &ProductsView::addToCartActionTriggered);

    QGraphicsView::setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    QScroller::grabGesture(viewport(), QScroller::LeftMouseButtonGesture);
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

void ProductsView::resizeEvent(QResizeEvent *event)
{
    if (scene())
    {
        qDebug() << event->size();
       // resize(event->size().width(), event->size().height());
    }

    QGraphicsView::resizeEvent(event);
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
    }

    return true;
}

bool ProductsView::handleTapAndHold(QTapAndHoldGesture *gesture)
{
    m_addToCartMenu->exec(gesture->position().toPoint());
    return true;
}

void ProductsView::scrollToTop()
{
    this->verticalScrollBar()->setValue(verticalScrollBar()->minimum());
}

void ProductsView::showEvent(QShowEvent *event)
{
    QGraphicsView::showEvent(event);
}


