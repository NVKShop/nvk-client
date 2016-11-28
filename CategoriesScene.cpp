#include "CategoriesScene.h"
#include <QDebug>

CategoriesScene::CategoriesScene(): QGraphicsScene()
{
}

void CategoriesScene::setItems(const QVector<Category *> &categories)
{
    QRectF catRect = categories.at(0)->boundingRect();

    int row = 0;
    foreach (Category* cat, categories)
    {
        cat->setPos(0, row * catRect.height()- 15);

        addItem(cat);
        row++;
    }
}
