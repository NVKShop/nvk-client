#include "CategoriesScene.h"
#include <QDebug>

CategoriesScene::CategoriesScene(): QGraphicsScene()
{
    connect(this, &CategoriesScene::selectionChanged, this, &CategoriesScene::itemSelectionChanged);
}

void CategoriesScene::setItems(const QVector<Category *> &categories)
{
    QRectF catRect = categories.at(0)->boundingRect();

    int row = 0;
    foreach (Category* cat, categories)
    {
        cat->setPos(0, row * catRect.height()+ 15);

        addItem(cat);
        row++;
    }
}

void CategoriesScene::itemSelectionChanged()
{
    QList<QGraphicsItem*> sitems = selectedItems();
    if (!sitems.size())
    {
        qDebug() << "0 selected";

        return;
    }
    else
    {
        if (sitems.size() == 1)
        {
            qDebug() << "1 selected";
            if(sitems.at(0) != m_lastSelectedItem)
            {
                m_lastSelectedItem = sitems[0];
            }
        }
        else
        {
            qDebug() << "2 selected";

            foreach (QGraphicsItem* item, sitems) {
                if (item != m_lastSelectedItem)
                {
                    m_lastSelectedItem->setSelected(false);
                    m_lastSelectedItem = item;
                }
            }
        }
    }
}
