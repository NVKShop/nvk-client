#include "Product.h"
#include <QDebug>
#include <QPainter>

Product::Product(const QPixmap & pixmap, const ProductProperty &property) :
    QGraphicsPixmapItem(pixmap), m_properties(property)
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

    rect.setWidth(rect.width() + 15);
    rect.setHeight(rect.height() + 25);
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
    painter->drawText(0, 0, m_properties.m_name);

    const int ypos = this->pixmap().rect().y() + this->pixmap().rect().height();
    painter->drawText(0, ypos, m_properties.m_description);

    QGraphicsPixmapItem::paint(painter, option, widget);
}
