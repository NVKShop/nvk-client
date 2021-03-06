#include "backend/graphics_items/Category.h"
#include <QDebug>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsSceneHoverEvent>

#define CATEGORY_BOUNDING_RECT_HEIGHT_PADDING 50
Category::Category(const QPixmap & pixmap, const CategoryProperty &property, const int width) :
    QGraphicsPixmapItem(pixmap), m_properties(property)
{

    setPixmap(pixmap.scaledToWidth(width, Qt::SmoothTransformation));

    setOffset(0, CATEGORY_BOUNDING_RECT_HEIGHT_PADDING/2);
    setFlag(QGraphicsItem::ItemIsSelectable);

    m_nameItem = new QGraphicsSimpleTextItem(m_properties.name());
    QFont nameItemFont;
    nameItemFont.setBold(true);
    nameItemFont.setPointSize(12);
    nameItemFont.setCapitalization(QFont::Capitalize);

    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::AllButtons);
    m_nameItem->setFont(nameItemFont);

    m_nameItem->setBrush(QColor::fromRgb(0xF5,0xB4,0x91));

    const int moveX = this->boundingRect().width()/ 3 - this->boundingRect().width() / 5;
    const int moveY = this->boundingRect().height() / 2;
    m_nameItem->moveBy(moveX, moveY);
    m_nameItem->setParentItem(this);
}

Category::~Category()
{
    delete m_nameItem;
}

QVariant Category::itemChange(GraphicsItemChange change,
                     const QVariant &value)
{
    if (change == QGraphicsItem::ItemSelectedHasChanged)
    {
        if (isSelected())
        {
            QBrush brush = m_nameItem->brush();
            brush.setColor(QColor::fromRgb(0xF7, 0xEB,0xE4));
            m_nameItem->setBrush(brush);
        }
        else
        {
            QBrush brush = m_nameItem->brush();
            brush.setColor(QColor::fromRgb(0xF5,0xB4,0x91));
            m_nameItem->setBrush(brush);
        }
    }
    return value;
}

QRectF Category::boundingRect() const
{
    QRectF rect = pixmap().rect();

    rect.setWidth(rect.width() );
    rect.setHeight(rect.height() + CATEGORY_BOUNDING_RECT_HEIGHT_PADDING);
    return rect;
}

void Category::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!isSelected())
    {
        setSelected(true);
    }
    else
    {
        setSelected(false);
    }
    QGraphicsPixmapItem::mousePressEvent(event);
}

void Category::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mouseReleaseEvent(event);
}

void Category::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mouseMoveEvent(event);
}

void Category::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsPixmapItem::paint(painter, option, widget);
}

void Category::hoverEnterEvent(QGraphicsSceneHoverEvent* e)
{

    QGraphicsPixmapItem::hoverEnterEvent(e);
}

void Category::hoverLeaveEvent(QGraphicsSceneHoverEvent *e)
{
    QGraphicsPixmapItem::hoverLeaveEvent(e);
}

QString Category::name()
{
    return m_properties.name();
}

CategoryProperty Category::properties() const
{
    return m_properties;
}
