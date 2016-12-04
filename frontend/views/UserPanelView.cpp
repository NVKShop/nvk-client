#include "frontend/views/UserPanelView.h"
#include <QGraphicsSimpleTextItem>
#include <QScreen>

UserPanelView::UserPanelView(UserPanelScene* scene, QWidget *parent) : QGraphicsView(scene,parent)
{

}

UserPanelView::UserPanelView(QWidget *parent) : QGraphicsView(parent)
{
    setInteractive(true);
}
