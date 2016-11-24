#include "Category.h"

#include <QDebug>
#include <QPainter>
#include <QGraphicsScene>
Category::Category(const QPixmap & pixmap, const Property &property, const int width) :
    QGraphicsPixmapItem(pixmap), m_name(property)
{
#ifdef Q_OS_ANDROID

#else
    setPixmap(pixmap.scaled(width, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setOffset(0, 25);
#endif

    setFlag(QGraphicsItem::ItemIsSelectable);

    m_NameItem = new QGraphicsSimpleTextItem(m_name.name());
    m_NameItem->moveBy(this->boundingRect().width()/2 - m_name.name().length(), this->boundingRect().height()/2);
    m_NameItem->setParentItem(this);
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

    rect.setWidth(rect.width() );
    rect.setHeight(rect.height() + 15);
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
