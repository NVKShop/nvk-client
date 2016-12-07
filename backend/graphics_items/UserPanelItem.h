#ifndef USERPANELITEM_H
#define USERPANELITEM_H

#include <QGraphicsPixmapItem>

class UserPanelItem : public QGraphicsPixmapItem
{
public:
    UserPanelItem(const QPixmap&, const int h);
    ~UserPanelItem();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) Q_DECL_OVERRIDE;

protected:
    QVariant itemChange(GraphicsItemChange change,
                         const QVariant &value);
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
private:

};

#endif // USERPANELITEM_H
