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
protected:
    QVariant itemChange(GraphicsItemChange change,
                         const QVariant &value) Q_DECL_OVERRIDE;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) Q_DECL_OVERRIDE;
    bool sceneEvent(QEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) Q_DECL_OVERRIDE;

Q_SIGNALS:
    void doubleClicked(Product* product);
private:
    int m_xPos;
    int m_yPos;
    ProductProperty m_properties;

    QGraphicsTextItem* m_productNameItem;
    QGraphicsTextItem* m_productDescriptionItem;
    QGraphicsDropShadowEffect* m_dropShadowEffect;
};

#endif // Product_H
