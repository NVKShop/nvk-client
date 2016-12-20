#include "backend/scenes/ProductsScene.h"
#include <QDebug>
#include <QGesture>
#include <QSwipeGesture>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsSceneMouseEvent>
#include <QScreen>
#include <QApplication>

ProductsScene::ProductsScene(const int viewWidth): QGraphicsScene(), m_viewWidth(viewWidth),
    m_scrollToTopItem(new QGraphicsPixmapItem)
{
    QBrush brush(Qt::gray);
    setBackgroundBrush(brush);
    QFont totalProductsFont;
#ifdef Q_OS_ANDROID
    totalProductsFont.setPointSize(10);
#else
    totalProductsFont.setPointSize(13);
#endif
    m_scrollToTopItem->setPixmap(QPixmap(":/images/top.png").scaledToWidth(viewWidth/5));

}

bool ProductsScene::isProductOnPosition()
{
    if (qgraphicsitem_cast<Product*>(focusItem()))
    {
        return true;
    }

    return false;
}

void ProductsScene::setItems(const QVector<Product *> &products)
{
    foreach (QGraphicsItem* p, items()) {
        if (dynamic_cast<Product*>(p))
            disconnect(dynamic_cast<Product*>(p), &Product::doubleClicked, this, &ProductsScene::productDoubleClicked);
        removeItem(p);
    }

    QRectF productRect;
    if (products.size())
    {
        productRect = products.at(0)->boundingRect();
    }
    int productsPerRow = m_viewWidth / productRect.width();

#ifdef Q_OS_ANDROID
    productsPerRow = 2;
#endif

    int row = 0;
    int col = 0;

    foreach (Product* prod, products)
    {
        prod->setPos(col * productRect.width(), row * productRect.height());
        prod->reset();
        addItem(prod);

        col++;
        if (col == productsPerRow)
        {
            row++;
            col = 0;
        }
        connect(prod, &Product::doubleClicked, this, &ProductsScene::productDoubleClicked);
    }

    QScreen *screen = QApplication::screens().at(0);
    const int h = screen->size().height();
    const bool addScrollTotopItem = (h < (row*productRect.height()*2));
    if (addScrollTotopItem)
    {
        m_scrollToTopItem->setPos(sceneRect().x() + sceneRect().width() -m_scrollToTopItem->pixmap().width() - 5, row* productRect.height() );
        m_scrollToTopItem->show();
        m_scrollToTopItem->update();
        addItem(m_scrollToTopItem);
    }
    setSceneRect(itemsBoundingRect());
}

ProductsScene::~ProductsScene()
{
    delete m_scrollToTopItem;
}

bool ProductsScene::event(QEvent *event)
{
    return QGraphicsScene::event(event);
}

void ProductsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QTransform t;

    QGraphicsItem* itemUnderMouse = itemAt(event->scenePos().x(), event->scenePos().y(),t);

    if (!qgraphicsitem_cast<Product*>(itemUnderMouse))
    {
        return;
    }
    else if (qgraphicsitem_cast<QGraphicsPixmapItem*>(itemUnderMouse) == m_scrollToTopItem)
    {
        emit scrollToTop();
    }
}
