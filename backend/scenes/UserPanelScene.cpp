#include "backend/scenes/UserPanelScene.h"
#include <QGraphicsSceneMouseEvent>

UserPanelScene::UserPanelScene() : QGraphicsScene(),
  m_welcomeUserText(new QGraphicsSimpleTextItem), m_productsInCartCountText(new QGraphicsSimpleTextItem),
  m_productsCount(0)
{
}

void UserPanelScene::setUserName(const QString &name)
{
#ifdef Q_OS_ANDROID
  //  m_welcomeUserText->setPos(w/6, h / 6);

#else
   // m_welcomeUserText->setPos(w/6, h / 6);
#endif
    QFont welcomeUserFont;

    welcomeUserFont.setPointSize(13);
    welcomeUserFont.setBold(true);

    m_welcomeUserText->setBrush(QBrush(QColor::fromRgb(0xB9, 0x78,0x26)));
    m_welcomeUserText->setFont(welcomeUserFont);
    m_welcomeUserText->setText(QLatin1String("Welcome ") + name);

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
    m_settingsItem->setPos(this->width() - this->width()/4, this->height() - m_settingsItem->pixmap().height());

    addItem(m_cartItem);
    m_cartItem->setPos(this->width() - (this->width()/3)*2 , this->height() - m_cartItem->pixmap().height());


    m_productsInCartCountText->setText("(0)");

    QFont cartItemsCountFont;
    cartItemsCountFont.setPointSize(15);
    cartItemsCountFont.setBold(true);

    m_productsInCartCountText->setPos(m_cartItem->pos().x() + m_cartItem->boundingRect().width() + 10, m_cartItem->pos().y());
    m_productsInCartCountText->setFont(cartItemsCountFont);
    addItem(m_productsInCartCountText);
    m_productsInCartCountText->show();
}

UserPanelScene::~UserPanelScene()
{
    delete m_welcomeUserText;
    delete m_cartItem;
    delete m_settingsItem;
    delete m_productsInCartCountText;
}

void UserPanelScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QTransform t;
    QGraphicsItem* itemUnderMouse = itemAt(event->scenePos().x(), event->scenePos().y(),t);

    if (!qgraphicsitem_cast<UserPanelItem*>(itemUnderMouse))
    {
        return;
    }
    else
    {
        UserPanelItem* panelItem = qgraphicsitem_cast<UserPanelItem*>(itemUnderMouse);
        if (panelItem == m_cartItem)
        {
            emit cartClicked();
        }
        else if (panelItem == m_settingsItem)
        {
            emit settingsClicked();
        }
    }
}

void UserPanelScene::itemAdded()
{
    ++m_productsCount;
    m_productsInCartCountText->setText(QLatin1String("(") + QString::number(m_productsCount)+QLatin1String(")"));
}

void UserPanelScene::itemRemoved()
{
    --m_productsCount;
    m_productsInCartCountText->setText(QLatin1String("(") + QString::number(m_productsCount)+QLatin1String(")"));
}

void UserPanelScene::itemsRemoved(const int count)
{
    m_productsCount-= count;
    m_productsInCartCountText->setText(QLatin1String("(") + QString::number(m_productsCount)+QLatin1String(")"));
}

void UserPanelScene::setQuantity(const int quantity)
{
    m_productsCount = quantity;
    m_productsInCartCountText->setText(QLatin1String("(") + QString::number(m_productsCount)+QLatin1String(")"));
}
