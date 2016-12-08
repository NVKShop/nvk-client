#include "backend/scenes/ProductsScene.h"
#include <QDebug>
#include <QGesture>
#include <QSwipeGesture>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsSceneMouseEvent>

ProductsScene::ProductsScene(const int viewWidth): QGraphicsScene(), m_viewWidth(viewWidth)
{
    QBrush brush(Qt::gray);
    setBackgroundBrush(brush);
    QFont totalProductsFont;
#ifdef Q_OS_ANDROID
    totalProductsFont.setPointSize(10);
#else
    totalProductsFont.setPointSize(13);
#endif
}

void ProductsScene::setItems(const QList<Product *> &products)
{
    foreach (QGraphicsItem* p, items()) {

        disconnect(reinterpret_cast<Product*>(p), &Product::doubleClicked, this, &ProductsScene::productDoubleClicked);
        removeItem(p);
    }

    QRectF productRect;
    if (products.size())
    {
        productRect = products.at(0)->boundingRect();
    }
    int productsPerRow = m_viewWidth / productRect.width();

#ifdef Q_OS_ANDROID
    productsPerRow = 2;
#endif

    int row = 0;
    int col = 0;
    foreach (Product* prod, products)
    {
        prod->setPos(col * productRect.width(), row * productRect.height());
        prod->reset();
        addItem(prod);

        col++;
        if (col == productsPerRow)
        {
            row++;
            col = 0;
        }
        connect(prod, &Product::doubleClicked, this, &ProductsScene::productDoubleClicked);
    }

    setSceneRect(itemsBoundingRect());
}

bool ProductsScene::event(QEvent *event)
{
    return QGraphicsScene::event(event);
}


void ProductsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QTransform t;
    QGraphicsItem* itemUnderMouse = itemAt(event->scenePos().x(), event->scenePos().y(),t);

    if (!reinterpret_cast<Product*>(itemUnderMouse))
    {
        return;
    }
    else
    {
        itemUnderMouse->setSelected(!itemUnderMouse->isSelected());
    }
}
