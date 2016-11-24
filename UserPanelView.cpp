#include "UserPanelView.h"

UserPanelView::UserPanelView(UserPanelScene* scene, QWidget *parent) : QGraphicsView(scene,parent)
{
}

UserPanelView::UserPanelView(QWidget *parent) : QGraphicsView(parent)
{
}
