#ifndef USERPANELVIEW_H
#define USERPANELVIEW_H

#include <QGraphicsView>
#include "backend/scenes/UserPanelScene.h"

class UserPanelView : public QGraphicsView
{

public:
    explicit UserPanelView(UserPanelScene* scene, QWidget* parent);
    UserPanelView(QWidget* parent);
private:
};
#endif // USERPANELVIEW_H
