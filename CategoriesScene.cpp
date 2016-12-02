#include "CategoriesScene.h"
#include <QDebug>

CategoriesScene::CategoriesScene(): QGraphicsScene()
{
    connect(this, &CategoriesScene::selectionChanged, this, &CategoriesScene::newCategory);
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

void CategoriesScene::newCategory()
{
    if (!selectedItems().isEmpty()) {
        emit selectionChangedNew(qgraphicsitem_cast<Category*>(selectedItems().at(0)));
    }
}

Category* CategoriesScene::selectedCategory() const
{
    return (selectedItems().isEmpty() ? nullptr : qgraphicsitem_cast<Category*>(selectedItems().at(0)));
}
