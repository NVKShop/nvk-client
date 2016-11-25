#include "ProductsScene.h"
#include <QDebug>
ProductsScene::ProductsScene(const int viewWidth): QGraphicsScene(), m_viewWidth(viewWidth)
{
}

void ProductsScene::setItems(const QVector<Product *> &products)
{
    QRectF productRect;
    if (products.size())
    {
        productRect = products.at(0)->boundingRect();
    }
    const int productsPerRow = m_viewWidth / productRect.width();

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
