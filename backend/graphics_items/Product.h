#ifndef Product_H
#define Product_H

#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsDropShadowEffect>

#include "backend/ProductProperty.h"
class Product : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Product(const QPixmap&, const ProductProperty& property);
    ~Product();

    void setProperties(const ProductProperty& properties);
    ProductProperty properties() const;
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) Q_DECL_OVERRIDE;
    void reset();
    QPixmap originalPixmap() const;
    void setQuantity(const int& quantity);
    int quantityInCart() const;
    QGraphicsPixmapItem* addedToCartItem() const;
    void setOriginalPixmap(const QPixmap& pixmap);

    QJsonObject asJson() const;
protected:
    QVariant itemChange(GraphicsItemChange change,
                         const QVariant &value) Q_DECL_OVERRIDE;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) Q_DECL_OVERRIDE;
    bool sceneEvent(QEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) Q_DECL_OVERRIDE;
public Q_SLOTS:
    void addedToCart();
    void removedFromCart();
Q_SIGNALS:
    void doubleClicked(Product* product);
private:
    ProductProperty m_properties;

    int m_quantityInCart;
    QPixmap m_originalPixmap;
    QGraphicsTextItem* m_productNameItem;
    QGraphicsTextItem* m_productDescriptionItem;
    QGraphicsDropShadowEffect* m_dropShadowEffect;
    QGraphicsPixmapItem* m_addedToCartItem;
};

#endif // Product_H
