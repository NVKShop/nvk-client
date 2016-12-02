#include "ProductsScene.h"
#include <QDebug>
#include <QGesture>
#include <QSwipeGesture>
#include <QBrush>

ProductsScene::ProductsScene(const int viewWidth): QGraphicsScene(), m_viewWidth(viewWidth)
{
    QBrush brush(Qt::gray);
    setBackgroundBrush(brush);
}

void ProductsScene::setItems(const QVector<Product *> &products)
{
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
        if (row == 0)
        {
            prod->setPos(col * productRect.width(), row * productRect.height()+ 15);
        }
        else
        {
            prod->setPos(col * productRect.width(), row * productRect.height());
        }
        addItem(prod);
        col++;
        if (col == productsPerRow)
        {
            row++;
            col = 0;
        }
    }
}

bool ProductsScene::event(QEvent *event)
{

    return QGraphicsScene::event(event);
}
