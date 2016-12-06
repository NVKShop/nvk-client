#ifndef CATEGORIESVIEW_H
#define CATEGORIESVIEW_H

#include <QGraphicsView>
#include "backend/scenes/CategoriesScene.h"

class QSwipeGesture;

class CategoriesView : public QGraphicsView
{
public:
    CategoriesView(CategoriesScene* scene, QWidget* parent);
    CategoriesView(QWidget* parent);
    Category* currentCategory() const;
    void setCurrentCategory(Category* cat);
private:
    Category* m_currentCategory;

protected:
    void mousePressEvent(QMouseEvent* event);
    void contextMenuEvent(QContextMenuEvent* event);
    bool handleSwipe(QSwipeGesture *gesture);
    bool viewportEvent(QEvent *event);

};

#endif // CATEGORIESVIEW_H
