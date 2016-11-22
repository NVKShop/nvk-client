#ifndef Product_H
#define Product_H

#include <QGraphicsPixmapItem>

class Product : public QGraphicsPixmapItem
{
public:
    explicit Product(const int x,const int y, const QPixmap& pixmap);

    ~Product();
    enum Category {
        // categories
    };

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) Q_DECL_OVERRIDE;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
private:
    int m_xPos;
    int m_yPos;
};

#endif // Product_H
