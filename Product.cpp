#include "Product.h"
#include <QDebug>

Product::Product(const int x, const int y, const QPixmap& pixmap):QGraphicsPixmapItem(pixmap) ,
    m_xPos(x), m_yPos(y)
{

}

Product::Product(const QPixmap & pixmap) : QGraphicsPixmapItem(pixmap)
{
#ifdef Q_OS_ANDROID

#else
    setPixmap(pixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
#endif
}

Product::~Product()
{

}

QRectF Product::boundingRect() const
{
    QRectF rect = pixmap().rect();
    rect.setWidth(rect.width() + 10);
    rect.setHeight(rect.height() + 10);
    return rect;
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
