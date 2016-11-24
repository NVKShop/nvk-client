#include "UserPanelItem.h"

UserPanelItem::UserPanelItem(const QPixmap & pixmap) :
    QGraphicsPixmapItem(pixmap)
{
#ifdef Q_OS_ANDROID

#else
    setPixmap(pixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setOffset(0, 25);
#endif

    setFlag(QGraphicsItem::ItemIsSelectable);
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
    QRectF rect = pixmap().rect();

    rect.setWidth(rect.width() + 45);
    rect.setHeight(rect.height() + 45);
    return rect;
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

