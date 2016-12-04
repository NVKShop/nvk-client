#include "backend/graphics_items/Product.h"
#include <QDebug>
#include <QPainter>
#include <QGraphicsSceneContextMenuEvent>
#include <QScreen>
#include <QApplication>
#include <QGestureEvent>
#include <QSwipeGesture>

#define PRODUCT_RECT_MARGIN 60
#define PRODUCT_TEXT_LEFT_MARGIN 25

Product::Product(const QPixmap & pixmap, const ProductProperty &property) :
    QGraphicsPixmapItem(pixmap), m_properties(property)
{

    QScreen *screen = QApplication::screens().at(0);
    int w = screen->size().width();
    // int h = screen->size().height();

    w-= w/5;

    setPixmap(pixmap.scaledToWidth(w/2 - PRODUCT_RECT_MARGIN *1.5, Qt::SmoothTransformation));
    setOffset(25,  15);

    setFlag(QGraphicsItem::ItemIsSelectable);
    setAcceptTouchEvents(true);

    m_productNameItem = new QGraphicsTextItem(m_properties.name());
    const qreal moveX = this->boundingRect().width()/2;

    m_dropShadowEffect = new QGraphicsDropShadowEffect;
    m_dropShadowEffect->setBlurRadius(4.0);
    m_dropShadowEffect->setOffset(2.0);

    m_productNameItem->setGraphicsEffect(m_dropShadowEffect);
    m_productNameItem->moveBy(PRODUCT_TEXT_LEFT_MARGIN, -25);
    QFont nameFont;
    QFont descriptionFont;
    m_productDescriptionItem = new QGraphicsTextItem(m_properties.description());

#ifdef Q_OS_ANDROID
    nameFont.setPointSize(10);
    descriptionFont.setPointSize(10);
    m_productNameItem->setFont(nameFont);
    m_productDescriptionItem->setFont(descriptionFont);
#else
    nameFont.setPointSize(13);
    descriptionFont.setPointSize(13);
    m_productNameItem->setFont(nameFont);
    m_productDescriptionItem->setFont(descriptionFont);
#endif

    m_productDescriptionItem->setTextWidth(this->boundingRect().width() - 5);
    const qreal moveY = this->boundingRect().height() - PRODUCT_RECT_MARGIN*1.5;
    m_productDescriptionItem->moveBy(PRODUCT_TEXT_LEFT_MARGIN, moveY);

    m_productNameItem->setParentItem(this);
    m_productDescriptionItem->setParentItem(this);

    setCacheMode(QGraphicsItem::NoCache);
}

Product::~Product()
{
}

QVariant Product::itemChange(GraphicsItemChange change,
                             const QVariant &value)
{
    if (change == QGraphicsItem::ItemSelectedHasChanged)
    {
        if(isSelected())
        {

        }
        else
        {

        }
    }
    return value;
}

QRectF Product::boundingRect() const
{
    QRectF rect = pixmap().rect();

    return rect.adjusted(15, -PRODUCT_RECT_MARGIN, PRODUCT_RECT_MARGIN, PRODUCT_RECT_MARGIN);
}

void Product::setProperties(const ProductProperty &properties)
{
    m_properties = properties;
}

ProductProperty Product::properties() const
{
    return m_properties;
}

void Product::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mousePressEvent(event);
}

void Product::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mouseReleaseEvent(event);
}

void Product::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mouseMoveEvent(event);
}

void Product::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsPixmapItem::paint(painter, option, widget);
}

void Product::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QGraphicsPixmapItem::contextMenuEvent(event);
}

void Product::reset()
{
    m_productNameItem->setParentItem(this);
    m_productDescriptionItem->setParentItem(this);

    m_productNameItem->show();
    m_productDescriptionItem->show();
    update();
}

bool Product::sceneEvent(QEvent *event)
{
    return QGraphicsPixmapItem::sceneEvent(event);
}


