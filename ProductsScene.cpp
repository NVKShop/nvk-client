#include "ProductsScene.h"
#include <QDebug>
ProductsScene::ProductsScene(const QRectF &sceneRect): QGraphicsScene(sceneRect)
{
}

void ProductsScene::setItems(const QVector<Product *> &products)
{
    QRectF sceneRect = this->sceneRect();
    QRectF productRect = products.at(0)->boundingRect();
    const int productsPerRow = sceneRect.width() / productRect.width();

    qDebug() << "sceneRect: " << sceneRect;

    qDebug() << "productRect: " << productRect;

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
