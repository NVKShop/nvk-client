#ifndef Product_H
#define Product_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSimpleTextItem>

#include "ProductProperty.h"
class Product : public QGraphicsPixmapItem
{
public:
    Product(const QPixmap&, const ProductProperty& property);
    ~Product();

    ProductProperty m_properties;
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) Q_DECL_OVERRIDE;

protected:
    QVariant itemChange(GraphicsItemChange change,
                         const QVariant &value) Q_DECL_OVERRIDE;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

private:
    int m_xPos;
    int m_yPos;

    QGraphicsSimpleTextItem* m_productNameItem;
    QGraphicsSimpleTextItem* m_productDescriptionItem;
};

#endif // Product_H
