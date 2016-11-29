#ifndef USERPANELSCENE_H
#define USERPANELSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>

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
