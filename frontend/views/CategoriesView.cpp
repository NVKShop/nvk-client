#include "frontend/views/CategoriesView.h"
#include <QMouseEvent>
#include <QContextMenuEvent>
#include <QScroller>
#include <QSwipeGesture>
#include <QScrollBar>

#include <QDebug>
CategoriesView::CategoriesView(CategoriesScene* scene, QWidget *parent) : QGraphicsView(scene,parent)
{
}

CategoriesView::CategoriesView(QWidget *parent) : QGraphicsView(parent)
{
    setInteractive(true);
    viewport()->grabGesture(Qt::SwipeGesture);
    QScroller::grabGesture(viewport(), QScroller::LeftMouseButtonGesture);
}

Category* CategoriesView::currentCategory() const
{
    return m_currentCategory;
}

void CategoriesView::setCurrentCategory(Category *cat)
{
    m_currentCategory = cat;
}

void CategoriesView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        event->accept();
        QGraphicsView::mousePressEvent(event);
    }
    else
    {
        event->ignore();
    }
}

void CategoriesView::contextMenuEvent(QContextMenuEvent *event)
{
    Q_UNUSED(event)
}

bool CategoriesView::viewportEvent(QEvent *event)
{
    if (event->type() == QEvent::Gesture)
    {
        QGestureEvent* e = static_cast<QGestureEvent*>(event);

        if (QGesture* swipe = e->gesture(Qt::SwipeGesture))
        {
            return handleSwipe(static_cast<QSwipeGesture*>(swipe));
        }
    }
    return QGraphicsView::viewportEvent(event);
}

bool CategoriesView::handleSwipe(QSwipeGesture *gesture)
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
