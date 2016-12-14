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
    int m_productsCount;
    QGraphicsSimpleTextItem* m_welcomeUserText;
    QGraphicsSimpleTextItem* m_productsInCartCountText;
    UserPanelItem* m_settingsItem;
    UserPanelItem* m_cartItem;
Q_SIGNALS:
    void cartClicked();
    void settingsClicked();
public Q_SLOTS:
    void itemAdded();
    void setQuantity(const int quantity);
    void itemRemoved();
    void itemsRemoved(const int count);
};

#endif // USERPANELSCENE_H
