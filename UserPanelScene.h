#ifndef USERPANELSCENE_H
#define USERPANELSCENE_H

#include <QGraphicsScene>

class UserPanelScene : public QGraphicsScene
{
public:
    UserPanelScene(const QRectF& parent);

private:
    void setupScene();
};

#endif // USERPANELSCENE_H
