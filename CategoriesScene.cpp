#include "CategoriesScene.h"

CategoriesScene::CategoriesScene(const QRectF &sceneRect): QGraphicsScene(sceneRect)
{
}


void CategoriesScene::setItems(const QVector<Category *> &categories)
{
    Q_UNUSED(categories)
}
