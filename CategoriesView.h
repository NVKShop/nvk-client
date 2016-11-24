#ifndef CATEGORIESVIEW_H
#define CATEGORIESVIEW_H

#include <QGraphicsView>
#include "CategoriesScene.h"
class CategoriesView : public QGraphicsView
{
public:
    CategoriesView(CategoriesScene* scene, QWidget* parent);
    CategoriesView(QWidget* parent);

};

#endif // CATEGORIESVIEW_H
