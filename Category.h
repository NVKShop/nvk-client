#ifndef CATEGORY_H
#define CATEGORY_H
#include <QGraphicsPixmapItem>
#include "Property.h"
class Category : public QGraphicsPixmapItem
{
public:
    Category(const QPixmap&, const Property& property, const int width);
    ~Category();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) Q_DECL_OVERRIDE;

protected:
    QVariant itemChange(GraphicsItemChange change,
                         const QVariant &value);
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

    Property m_name;
private:
    QGraphicsSimpleTextItem* m_NameItem;
};

#endif // CATEGORY_H
