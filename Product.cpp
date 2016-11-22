#include "Product.h"

Product::Product(const int x, const int y, const QPixmap& pixmap):QGraphicsPixmapItem(pixmap) ,
    m_xPos(x), m_yPos(y)
{

}

Product::Product(const QPixmap & pixmap) : QGraphicsPixmapItem(pixmap)
{
}

Product::~Product()
{

}

QRectF Product::boundingRect() const
{
    return pixmap().rect();
}

void Product::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
}

void Product::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
}

void Product::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
}

void Product::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsPixmapItem::paint(painter, option, widget);
}
