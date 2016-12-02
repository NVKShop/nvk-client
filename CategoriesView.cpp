#include "CategoriesView.h"

CategoriesView::CategoriesView(CategoriesScene* scene, QWidget *parent) : QGraphicsView(scene,parent)
{
}

CategoriesView::CategoriesView(QWidget *parent) : QGraphicsView(parent)
{
    setInteractive(true);
}

Category* CategoriesView::currentCategory() const
{
    return m_currentCategory;
}

void CategoriesView::setCurrentCategory(Category *cat)
{
    m_currentCategory = cat;
}
