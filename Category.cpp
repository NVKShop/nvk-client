#include "Category.h"

#include <QDebug>
#include <QPainter>

Category::Category(const QPixmap & pixmap, const Property &property) :
    QGraphicsPixmapItem(pixmap), m_name(property)
{
#ifdef Q_OS_ANDROID

#else
    setPixmap(pixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setOffset(0, 25);
#endif

    setFlag(QGraphicsItem::ItemIsSelectable);

}

Category::~Category()
{
}

QVariant Category::itemChange(GraphicsItemChange change,
                     const QVariant &value)
{
    if (change == QGraphicsItem::ItemSelectedHasChanged)
    {
        //
    }
    return value;
}

QRectF Category::boundingRect() const
{
    QRectF rect = pixmap().rect();

    rect.setWidth(rect.width() + 45);
    rect.setHeight(rect.height() + 45);
    return rect;
}

void Category::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
}

void Category::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
}

void Category::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
}

void Category::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsPixmapItem::paint(painter, option, widget);
}
