#ifndef CATEGORIESSCENE_H
#define CATEGORIESSCENE_H

#include <QGraphicsScene>
#include "backend/graphics_items/Category.h"
class CategoriesScene : public QGraphicsScene
{
    Q_OBJECT
public:
    CategoriesScene();
    void setItems(const QVector<Category*>& categories);
    void addCategory(Category* item);
    Category* selectedCategory() const;
    void removeLast();
    QVector<Category*> categories() const;
private:
    QVector<Category*> m_categories;
private Q_SLOTS:
    void newCategory();
Q_SIGNALS:
    void selectionChangedNew(Category* newCat);
};

#endif // CATEGORIESSCENE_H
