#ifndef CATEGORIESSCENE_H
#define CATEGORIESSCENE_H

#include <QGraphicsScene>
#include "Category.h"
class CategoriesScene : public QGraphicsScene
{
public:
    CategoriesScene();
    void setItems(const QVector<Category*>& categories);
private:
};

#endif // CATEGORIESSCENE_H
