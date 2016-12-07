#include "backend/scenes/UserPanelScene.h"

UserPanelScene::UserPanelScene() : QGraphicsScene(),
  m_welcomeUserText(new QGraphicsSimpleTextItem)
{
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

#include <QDebug>

void UserPanelScene::setupScene()
{
    QBrush brush(QColor::fromRgb(0x63,0x63,0x63));
    setBackgroundBrush(brush);

    m_settingsItem = new UserPanelItem(QPixmap(":/images/settings.png"), this->height() - this->height()/4);
    m_cartItem = new UserPanelItem(QPixmap(":/images/cart.png"), this->height() - this->height()/4);

    addItem(m_settingsItem);

    qDebug() << this->width() << this-> height();
    m_settingsItem->moveBy(this->width() - this->width()/12, this->sceneRect().height() - m_settingsItem->pixmap().height());

    addItem(m_cartItem);
    m_cartItem->moveBy(this->width() - this->width()/3 , this->sceneRect().height() - m_cartItem->pixmap().height());
}

UserPanelScene::~UserPanelScene()
{
    delete m_welcomeUserText;
    delete m_cartItem;
    delete m_settingsItem;
}
