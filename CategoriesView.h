#ifndef CATEGORIESVIEW_H
#define CATEGORIESVIEW_H

#include <QGraphicsView>
#include "CategoriesScene.h"
class CategoriesView : public QGraphicsView
{
public:
    CategoriesView(CategoriesScene* scene, QWidget* parent);
    CategoriesView(QWidget* parent);
    Category* currentCategory() const;
    void setCurrentCategory(Category* cat);
private:
    Category* m_currentCategory;
};

#endif // CATEGORIESVIEW_H
