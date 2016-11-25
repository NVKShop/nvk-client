#include "ProductsView.h"
#include <QMouseEvent>
#include <QTouchEvent>

ProductsView::ProductsView(ProductsScene* scene, QWidget *parent) : QGraphicsView(scene,parent)
{
}

ProductsView::ProductsView(QWidget *parent) : QGraphicsView(parent)
{
    setInteractive(true);
    setAttribute(Qt::WA_AcceptTouchEvents);
    viewport()->setAttribute(Qt::WA_AcceptTouchEvents);
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
    if (event->type() == QEvent::TouchBegin)
    {
        QTouchEvent* event = static_cast<QTouchEvent*>(event);
        if (!event->touchPoints().isEmpty())
        {
            const QTouchEvent::TouchPoint point = event->touchPoints().front();
            m_mouseDownPosY = point.pos().y();
        }
    }
    else if (event->type() == QEvent::TouchUpdate)
    {
        QTouchEvent* event = static_cast<QTouchEvent*>(event);
        if (!event->touchPoints().isEmpty())
        {
            const QTouchEvent::TouchPoint point = event->touchPoints().back();
            scrollContentsBy(0, point.pos().y() - m_mouseDownPosY);
        }
    }
    else if (event->type() == QEvent::TouchEnd)
    {
        QTouchEvent* event = static_cast<QTouchEvent*>(event);
        m_mouseDownPosY = 0;
    }
    return QGraphicsView::viewportEvent(event);
}
