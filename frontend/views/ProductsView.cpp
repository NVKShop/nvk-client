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
#include <QTimeLine>

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

    m_addToCartMenu = new QMenu(this);

    m_addToCartAction = new QAction(QIcon(QPixmap(":/images/addToCartAction.png")),QLatin1String("Add to cart"));
    m_addToCartMenu->addAction(m_addToCartAction);

    connect(m_addToCartAction, &QAction::triggered, this, &ProductsView::emitAddToCartActionTriggered);

    QGraphicsView::setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    QScroller::grabGesture(viewport(), QScroller::LeftMouseButtonGesture);
}

void ProductsView::mouseMoveEvent(QMouseEvent *e)
{
    QGraphicsView::mouseMoveEvent(e);
}

ProductsView::~ProductsView()
{
    delete m_addToCartAction;
    delete m_addToCartMenu;
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
    ProductsScene* sscene = qobject_cast<ProductsScene*>(scene());

    if (sscene->isProductOnPosition())
    {
        m_addToCartMenu->exec(gesture->position().toPoint());
    }
    return true;
}

void ProductsView::scrollToTop()
{
    QTimeLine* timeLine = new QTimeLine(1300);
    timeLine->setDirection(QTimeLine::Backward);
    timeLine->setFrameRange(0, this->verticalScrollBar()->value());
    timeLine->start();

    connect(timeLine, &QTimeLine::frameChanged, this->verticalScrollBar(), &QScrollBar::setValue);
    connect(timeLine, &QTimeLine::finished, timeLine, &QTimeLine::deleteLater);
}

void ProductsView::showEvent(QShowEvent *event)
{
    QGraphicsView::showEvent(event);
}
#include <QJsonObject>
void ProductsView::emitAddToCartActionTriggered()
{
    ProductsScene* sscene = qobject_cast<ProductsScene*>(scene());
    QTransform t;


    Product* p = qgraphicsitem_cast<Product*>(
                sscene->itemAt(QPointF(mapToScene(m_addToCartMenu->pos())), t));

    emit addToCartActionTriggered(p);

    qDebug() << m_addToCartMenu->pos();
    qDebug() << p->asJson();
}


