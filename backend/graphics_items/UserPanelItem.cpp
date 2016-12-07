#include "backend/graphics_items/UserPanelItem.h"

UserPanelItem::UserPanelItem(const QPixmap & pixmap, const int h) :
    QGraphicsPixmapItem(pixmap)
{

    setPixmap(pixmap.scaledToHeight(h, Qt::SmoothTransformation));

    setFlag(QGraphicsItem::ItemIsSelectable);
    setEnabled(true);
}

UserPanelItem::~UserPanelItem()
{
}

QVariant UserPanelItem::itemChange(GraphicsItemChange change,
                     const QVariant &value)
{
    if (change == QGraphicsItem::ItemSelectedHasChanged)
    {
        //
    }
    return value;
}

QRectF UserPanelItem::boundingRect() const
{
    return pixmap().rect();
}

void UserPanelItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
}

void UserPanelItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
}

void UserPanelItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
}

void UserPanelItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsPixmapItem::paint(painter, option, widget);
}

