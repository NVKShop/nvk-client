#include "CategoriesView.h"
#include <QMouseEvent>
#include <QContextMenuEvent>
#include <QDebug>
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

void CategoriesView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        event->accept();
        QGraphicsView::mousePressEvent(event);
    }
    else
    {
        qDebug() << "NOT LEFT";
        event->ignore();
    }
}

void CategoriesView::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug() << "CME";
    Q_UNUSED(event)
}
