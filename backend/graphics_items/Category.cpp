#include "backend/graphics_items/Category.h"
#include <QDebug>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsSceneHoverEvent>

#define CATEGORY_BOUNDING_RECT_HEIGHT_PADDING 50
Category::Category(const QPixmap & pixmap, const Property &property, const int width) :
    QGraphicsPixmapItem(pixmap), m_name(property)
{

    setPixmap(pixmap.scaledToWidth(width, Qt::SmoothTransformation));

    setOffset(0, CATEGORY_BOUNDING_RECT_HEIGHT_PADDING/2);
    setFlag(QGraphicsItem::ItemIsSelectable);

    m_nameItem = new QGraphicsSimpleTextItem(m_name.name());
    QFont nameItemFont;
    nameItemFont.setBold(true);
    nameItemFont.setPointSize(10);
    nameItemFont.setCapitalization(QFont::Capitalize);

    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::AllButtons);
    m_nameItem->setFont(nameItemFont);

    m_nameItem->setBrush(Qt::green);

    const int moveX = this->boundingRect().width()/ 2 - this->boundingRect().width() / 3;
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
            brush.setColor(Qt::white);
            m_nameItem->setBrush(brush);
        }
        else
        {
            QBrush brush = m_nameItem->brush();
            brush.setColor(Qt::green);
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
    return m_name.name();
}
