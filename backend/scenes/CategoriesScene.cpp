#include "backend/scenes/CategoriesScene.h"
#include <QDebug>
#include <QBrush>

CategoriesScene::CategoriesScene(): QGraphicsScene()
{
    connect(this, &CategoriesScene::selectionChanged, this, &CategoriesScene::newCategory);
    QBrush brush(Qt::black);
    setBackgroundBrush(brush);
}


void CategoriesScene::setItems(const QVector<Category *> &categories)
{
    QRectF catRect = categories.at(0)->boundingRect();

    int row = 0;
    foreach (Category* cat, categories)
    {
        if (row == 0)
        {
            cat->setSelected(true);
        }
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
