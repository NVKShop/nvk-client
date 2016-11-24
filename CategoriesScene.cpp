#include "CategoriesScene.h"
#include <QDebug>

CategoriesScene::CategoriesScene(const QRectF &sceneRect): QGraphicsScene(sceneRect)
{
}


void CategoriesScene::setItems(const QVector<Category *> &categories)
{
    QRectF sceneRect = this->sceneRect();
    QRectF catRect = categories.at(0)->boundingRect();

    qDebug() << "cat sceneRect: " << sceneRect;
    qDebug() << "catrect: " << catRect;

    int row = 0;
    foreach (Category* cat, categories)
    {
        cat->setPos(0, row * catRect.height()+ 15);

        addItem(cat);
        row++;
    }
}
