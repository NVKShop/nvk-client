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

        item->setPos(row * productRect.width(), col * productRect.height());
        addItem(item);
        if (row == productsPerRow)
        {
            col++;
            row = 0;
        }
        row++;
    }
}
