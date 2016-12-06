#ifndef USERPANELSCENE_H
#define USERPANELSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include "backend/graphics_items/UserPanelItem.h"
class UserPanelScene : public QGraphicsScene
{

public:
    UserPanelScene();
    ~UserPanelScene();
    void setUserName(const QString& name);

private:
    void setupScene();
    QGraphicsSimpleTextItem* m_welcomeUserText;

};

#endif // USERPANELSCENE_H
