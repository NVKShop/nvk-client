#include "UserPanelScene.h"

UserPanelScene::UserPanelScene() : QGraphicsScene(),
  m_welcomeUserText(new QGraphicsSimpleTextItem)

{
    setupScene();
}

void UserPanelScene::setUserName(const QString &name)
{

    int w = this->width();
    int h = this->height();
#ifdef Q_OS_ANDROID
    m_welcomeUserText->moveBy(w/2, h / 4);

#else
    m_welcomeUserText->moveBy(w/2, h / 4);
#endif
    QFont welcomeUserFont;

    welcomeUserFont.setPointSize(13);
    welcomeUserFont.setBold(true);

    m_welcomeUserText->setBrush(Qt::green);
    m_welcomeUserText->setFont(welcomeUserFont);
    m_welcomeUserText->setText("Welcome " + name);

    addItem(m_welcomeUserText);
}

void UserPanelScene::setupScene()
{
}

UserPanelScene::~UserPanelScene()
{
    delete m_welcomeUserText;
}
