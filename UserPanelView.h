#ifndef USERPANELVIEW_H
#define USERPANELVIEW_H

#include <QGraphicsView>
#include "UserPanelScene.h"

class UserPanelView : public QGraphicsView
{
public:
    explicit UserPanelView(UserPanelScene* scene, QWidget* parent);
    UserPanelView(QWidget* parent);};

#endif // USERPANELVIEW_H
