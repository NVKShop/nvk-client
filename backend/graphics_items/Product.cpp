#include "backend/graphics_items/Product.h"
#include <QDebug>
#include <QPainter>
#include <QGraphicsSceneContextMenuEvent>
#include <QScreen>
#include <QApplication>
#include <QGestureEvent>
#include <QSwipeGesture>
#include <QFontMetrics>

#define PRODUCT_RECT_MARGIN 100
#define PRODUCT_TEXT_LEFT_MARGIN 100

Product::Product(const QPixmap & pixmap, const ProductProperty &property) : QObject(),
    QGraphicsPixmapItem(pixmap), m_properties(property)
{

    QScreen *screen = QApplication::screens().at(0);
    int w = screen->size().width();
    // int h = screen->size().height();

    w-= w/5;

    int originalScaled;

#ifdef Q_OS_ANDROID
    originalScaled = screen->size().width() - screen->size().width() / 4;
#else
    originalScaled = pixmap.size().width();
#endif
    m_originalPixmap = pixmap.scaledToWidth(originalScaled);

    setPixmap(pixmap.scaledToWidth(w/2 - PRODUCT_RECT_MARGIN *1.8, Qt::SmoothTransformation));
    setOffset(100,  15);


    setFlag(QGraphicsItem::ItemIsSelectable);
    setAcceptTouchEvents(true);

    m_productNameItem = new QGraphicsTextItem(m_properties.name());

    m_dropShadowEffect = new QGraphicsDropShadowEffect;
    m_dropShadowEffect->setBlurRadius(4.0);
    m_dropShadowEffect->setOffset(2.0);

    m_productNameItem->setGraphicsEffect(m_dropShadowEffect);
    m_productNameItem->moveBy(PRODUCT_TEXT_LEFT_MARGIN, -25);
    QFont nameFont;
    QFont descriptionFont;
    m_productDescriptionItem = new QGraphicsTextItem;

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

    m_properties.setShortDescription(m_properties.description().left(this->boundingRect().width()/ descriptionFont.pointSize() - 5)+"...");

    m_productDescriptionItem->setPlainText(m_properties.shortDescription());

    m_productDescriptionItem->setTextWidth(this->boundingRect().width() - 5);
    const qreal moveY = this->boundingRect().height() - PRODUCT_RECT_MARGIN;
    m_productDescriptionItem->moveBy(PRODUCT_TEXT_LEFT_MARGIN, moveY);

    m_productNameItem->setParentItem(this);
    m_productDescriptionItem->setParentItem(this);

    setCacheMode(QGraphicsItem::ItemCoordinateCache);

    m_addToCartItem = new QGraphicsPixmapItem;
    QPixmap addToCartImg(":/images/addToCart.png");
    m_addToCartItem->setPixmap(addToCartImg.scaledToWidth(this->pixmap().width()/4));
    m_addToCartItem->moveBy(PRODUCT_TEXT_LEFT_MARGIN/4, -25);
    m_addToCartItem->setParentItem(this);
    m_addToCartItem->hide();

}

Product::~Product()
{
}

QVariant Product::itemChange(GraphicsItemChange change,
                             const QVariant &value)
{
    if (change == QGraphicsItem::ItemSelectedHasChanged)
    {
        if (isSelected())
        {
            m_addToCartItem->show();
        }
        else
        {
            m_addToCartItem->hide();
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
    if (event->button() & Qt::LeftButton)
    {
   //     setSelected(!isSelected());
    }

    QGraphicsPixmapItem::mousePressEvent(event);
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
    m_addToCartItem->setParentItem(this);

    m_productNameItem->show();
    m_productDescriptionItem->show();
    update();
}

bool Product::sceneEvent(QEvent *event)
{
    return QGraphicsPixmapItem::sceneEvent(event);
}

void Product::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    emit doubleClicked(this);
}

QPixmap Product::originalPixmap() const
{
    return m_originalPixmap;
}

QGraphicsPixmapItem* Product::addToCartItem() const
{
    return m_addToCartItem;
}


