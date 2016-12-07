#ifndef USERPANELSCENE_H
#define USERPANELSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include "backend/graphics_items/UserPanelItem.h"
class UserPanelScene : public QGraphicsScene
{
    Q_OBJECT
public:
    UserPanelScene();
    ~UserPanelScene();
    void setUserName(const QString& name);
    void setupScene();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    QGraphicsSimpleTextItem* m_welcomeUserText;

    UserPanelItem* m_settingsItem;
    UserPanelItem* m_cartItem;
Q_SIGNALS:
    void cartClicked();
    void settingsClicked();
};

#endif // USERPANELSCENE_H
