#include "ProductsScene.h"

ProductsScene::ProductsScene(const QRectF &sceneRect): QGraphicsScene(sceneRect)
{

}

void ProductsScene::setItems(const QVector<Product *> &products)
{
    QRectF sceneRect = this->sceneRect();
    QRectF productRect = products.at(0)->boundingRect();
    const int productsPerRow = sceneRect.width() / productRect.width();

    int row = 0;
    int col = 0;
    for (int i = 0; i < products.size(); ++i)
    {
        Product* item = products[i];

        item->setPos(row * productRect.width() + 3, col * productRect.height() + 3);
        if (row == productsPerRow)
        {
            col++;
            row = 0;
        }
        row++;
    }
}
