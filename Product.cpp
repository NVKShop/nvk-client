#include "Product.h"
#include <QDebug>
#include <QPainter>

Product::Product(const QPixmap & pixmap, const ProductProperty &property) :
    QGraphicsPixmapItem(pixmap), m_properties(property)
{
#ifdef Q_OS_ANDROID

#else
    setPixmap(pixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setOffset(0, 25);
#endif

    setFlag(QGraphicsItem::ItemIsSelectable);

    m_productNameItem = new QGraphicsSimpleTextItem(m_properties.m_name);
    const qreal moveX = this->boundingRect().width()/2;

    m_productNameItem->moveBy(0, 5);
    m_productNameItem->setParentItem(this);

    m_productDescriptionItem = new QGraphicsSimpleTextItem(m_properties.m_description);

    const qreal moveY = this->boundingRect().height() - 15;
    m_productDescriptionItem->moveBy(0, moveY);
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

    rect.setWidth(rect.width() + 45);
    rect.setHeight(rect.height() + 45);
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
