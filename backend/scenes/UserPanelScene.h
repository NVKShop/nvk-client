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
    void setupScene();

private:
    QGraphicsSimpleTextItem* m_welcomeUserText;

    UserPanelItem* m_settingsItem;
    UserPanelItem* m_cartItem;
};

#endif // USERPANELSCENE_H
