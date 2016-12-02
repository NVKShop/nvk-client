#include "Product.h"
#include <QDebug>
#include <QPainter>
#include <QGraphicsSceneContextMenuEvent>
#include <QScreen>
#include <QApplication>
#include <QGestureEvent>
#include <QSwipeGesture>

#define PRODUCT_RECT_MARGIN 60
Product::Product(const QPixmap & pixmap, const ProductProperty &property) :
    QGraphicsPixmapItem(pixmap), m_properties(property)
{

    QScreen *screen = QApplication::screens().at(0);
    int w = screen->size().width();
    // int h = screen->size().height();

    w-= w/5;

    setPixmap(pixmap.scaledToWidth(w/2 - PRODUCT_RECT_MARGIN *1.5, Qt::SmoothTransformation));
    setOffset(35, 35);

    setFlag(QGraphicsItem::ItemIsSelectable);
    setAcceptTouchEvents(true);

    m_productNameItem = new QGraphicsTextItem(m_properties.name());
    const qreal moveX = this->boundingRect().width()/2;

    m_dropShadowEffect = new QGraphicsDropShadowEffect;
    m_dropShadowEffect->setBlurRadius(4.0);
    m_dropShadowEffect->setOffset(2.0);

    m_productNameItem->setGraphicsEffect(m_dropShadowEffect);
    m_productNameItem->moveBy(15, 5);
    QFont nameFont;
    QFont descriptionFont;
    m_productDescriptionItem = new QGraphicsTextItem(m_properties.m_description);

#ifdef Q_OS_ANDROID
    nameFont.setPointSize(10);
    descriptionFont.setPointSize(10);
    m_productNameItem->setFont(nameFont);
    m_productDescriptionItem->setFont(descriptionFont);
#else
    nameFont.setPointSize(13);
    descriptionFont.setPointSize(13);
    m_productNameItem->setFont(nameFont);
    m_productDescriptionItem->setFont(descriptionFont);
#endif

    m_productDescriptionItem->setTextWidth(this->boundingRect().width() - 5);
    const qreal moveY = this->boundingRect().height() - 80;
    m_productDescriptionItem->moveBy(0, moveY);

    m_productNameItem->setParentItem(this);
    m_productDescriptionItem->setParentItem(this);

}

Product::~Product()
{
}

QVariant Product::itemChange(GraphicsItemChange change,
                             const QVariant &value)
{
    if (change == QGraphicsItem::ItemSelectedHasChanged)
    {
        //
    }
    return value;
}

QRectF Product::boundingRect() const
{
    QRectF rect = pixmap().rect();

    rect.setWidth(rect.width() + PRODUCT_RECT_MARGIN);
    rect.setHeight(rect.height() + PRODUCT_RECT_MARGIN);
    return rect;
}

void Product::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mousePressEvent(event);
}

void Product::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mouseReleaseEvent(event);
}

void Product::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mouseMoveEvent(event);
}

void Product::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsPixmapItem::paint(painter, option, widget);
}

void Product::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{

    QGraphicsPixmapItem::contextMenuEvent(event);
}

bool Product::sceneEvent(QEvent *event)
{
    if (event->type() == QEvent::Gesture)
    {
        QGestureEvent* e = static_cast<QGestureEvent*>(event);

        if (QGesture* swipe = e->gesture(Qt::SwipeGesture))
        {
            qDebug() << "swipe";
            // return handleSwipe(static_cast<QSwipeGesture*>(swipe));
        }
    }

    return QGraphicsPixmapItem::sceneEvent(event);
}
