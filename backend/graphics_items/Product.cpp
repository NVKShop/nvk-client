#include "backend/graphics_items/Product.h"
#include <QDebug>
#include <QPainter>
#include <QGraphicsSceneContextMenuEvent>
#include <QScreen>
#include <QApplication>
#include <QGestureEvent>
#include <QSwipeGesture>
#include <QFontMetrics>
#include <QPixmap>
#include <QStyleOptionGraphicsItem>
#include <QStyle>
#include <QJsonObject>

#define PRODUCT_RECT_MARGIN 100
#define PRODUCT_TEXT_LEFT_MARGIN 80

Product::Product(const QPixmap & pixmap, const ProductProperty &property) : QObject(),
    QGraphicsPixmapItem(pixmap), m_properties(property), m_quantityInCart(0)
{

    QScreen *screen = QApplication::screens().at(0);
    int w = screen->size().width();

    w-= w/5;

    int originalScaled;

#ifdef Q_OS_ANDROID
    originalScaled = screen->size().width() - screen->size().width() / 4;
#else
    originalScaled = pixmap.size().width();
#endif
    m_originalPixmap = pixmap.scaledToWidth(originalScaled);

    setPixmap(pixmap.scaledToWidth(w/2 - PRODUCT_RECT_MARGIN *1.8, Qt::SmoothTransformation));
    setOffset(PRODUCT_TEXT_LEFT_MARGIN/2,  85);

    setFlag(QGraphicsItem::ItemIsSelectable);
    setAcceptTouchEvents(true);

    m_productNameItem = new QGraphicsTextItem(m_properties.name());

    m_dropShadowEffect = new QGraphicsDropShadowEffect;
    m_dropShadowEffect->setBlurRadius(4.0);
    m_dropShadowEffect->setOffset(2.0);

    m_productNameItem->setGraphicsEffect(m_dropShadowEffect);
    m_productNameItem->moveBy(PRODUCT_TEXT_LEFT_MARGIN, 0);
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
    const qreal moveY = pos().y() + this->pixmap().height() + offset().y() + 10;
    m_productDescriptionItem->moveBy(PRODUCT_TEXT_LEFT_MARGIN, moveY);

    m_productNameItem->setParentItem(this);
    m_productDescriptionItem->setParentItem(this);

    setCacheMode(QGraphicsItem::ItemCoordinateCache);

    m_addedToCartItem = new QGraphicsPixmapItem;
    QPixmap addedToCartImg(":/images/inCart.png");
    m_addedToCartItem->setPixmap(addedToCartImg.scaledToWidth(this->pixmap().width()/4));
    m_addedToCartItem->moveBy(PRODUCT_TEXT_LEFT_MARGIN - m_addedToCartItem->pixmap().width() - 10, 0);
    m_addedToCartItem->setParentItem(this);
    m_addedToCartItem->hide();

}

Product::~Product()
{
    delete m_addedToCartItem;
    delete m_dropShadowEffect;
    delete m_productDescriptionItem;
    delete m_productNameItem;
}

QVariant Product::itemChange(GraphicsItemChange change,
                             const QVariant &value)
{
    if (change == QGraphicsItem::ItemSelectedHasChanged)
    {

    }
    return value;
}

QRectF Product::boundingRect() const
{
    QRectF rect = pixmap().rect();
    rect.setHeight(rect.height() + PRODUCT_RECT_MARGIN*2);
    rect.setWidth(rect.width() + PRODUCT_RECT_MARGIN);
    return rect;
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
        setSelected(!isSelected());
        update(boundingRect());
    }

    QGraphicsPixmapItem::mousePressEvent(event);
}

void Product::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mouseMoveEvent(event);
}

void Product::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (isSelected())
    {
        QPen pen;
        pen.setWidth(4);
        pen.setColor(Qt::red);
        pen.setStyle(Qt::SolidLine);
        painter->setPen(pen);
        painter->drawRect(boundingRect().x()+5, boundingRect().y()+5, boundingRect().bottomRight().x()-10, boundingRect().bottomRight().y()-10);
    }
    QStyleOptionGraphicsItem myOption(*option);
    myOption.state &= ~QStyle::State_Selected;
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
    m_addedToCartItem->setParentItem(this);

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

QGraphicsPixmapItem* Product::addedToCartItem() const
{
    return m_addedToCartItem;
}

void Product::addedToCart()
{
    m_quantityInCart++;
    m_addedToCartItem->show();
}

void Product::removedFromCart()
{
    m_addedToCartItem->hide();
    m_quantityInCart = 0;
}

int Product::quantityInCart() const
{
    return m_quantityInCart;
}

void Product::setQuantity(const int& quantity)
{
    m_quantityInCart = quantity;
}

QJsonObject Product::asJson() const
{
    QJsonObject prodObj;

    QJsonValue prodId(static_cast<int>(m_properties.id()));
    QJsonValue productQuantityInCart(m_quantityInCart);

    prodObj["productId"] = prodId;
    prodObj["quantity"] = productQuantityInCart;

    return prodObj;
}





