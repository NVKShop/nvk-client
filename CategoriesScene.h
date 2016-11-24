#ifndef CATEGORIESSCENE_H
#define CATEGORIESSCENE_H

#include <QGraphicsScene>
#include "Category.h"
class CategoriesScene : public QGraphicsScene
{
public:
    CategoriesScene(const QRectF& parent);
    void setItems(const QVector<Category*>& categories);
};

#endif // CATEGORIESSCENE_H
