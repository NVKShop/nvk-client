#include "Product.h"
#include <QDebug>

Product::Product(const int x, const int y, const QPixmap& pixmap):QGraphicsPixmapItem(pixmap) ,
    m_xPos(x), m_yPos(y)
{

}

Product::Product(const QPixmap & pixmap) : QGraphicsPixmapItem(pixmap)
{

    setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio));
    qDebug() << this->pixmap().size();

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
