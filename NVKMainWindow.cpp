#include "NVKMainWindow.h"
#include "ui_nvkmainwindow.h"
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QScrollBar>
#include <QDebug>

NVKMainWindow::NVKMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NVKMainWindow), m_order(new Order())
{
    setWindowTitle("NVK Shop");
    ui->setupUi(this);

#ifdef Q_OS_ANDROID
    //Set sizes for Android

    QString barstyle =  "QScrollBar:horizontal {height: 5px;}" "QScrollBar:vertical {width: 5px;}";
    ui->productsView->verticalScrollBar()->setStyleSheet(barstyle);
    ui->categoriesView->verticalScrollBar()->setStyleSheet(barstyle);
    showFullScreen();

#else

    QDesktopWidget* dw = QApplication::desktop();
    dw->availableGeometry(dw->primaryScreen());

    resize( dw->availableGeometry(dw->primaryScreen()).size());
    //Desktop sizes
#endif
    qDebug() << ui->productsView->width();

    setupViews();
}

void NVKMainWindow::setupViews()
{
    // test items

    auto p = [](int count) -> QVector<Product*>
    {
        QVector<Product*> products;
        products.reserve(count);
        products.resize(count);

        for(int i = 0; i < count; ++i)
        {
            ProductProperty prop("Product " + QString::number(i), "This is a fckin product you dumbass", ProductProperty::IDK);
            Product* prod = new Product(QPixmap(":/noImage.png"), prop);
            products[i] = prod;
        }

        return  products;
    };

    auto c = [](int count,const int w) ->QVector<Category*>
    {
        QVector<Category*> categories;
        categories.reserve(count);
        categories.resize(count);

        for (int i = 0; i < count; ++i)
        {
            Property prop("Category " + QString::number(i));
            Category* cat = new Category(QPixmap(":/catBg.png"), prop, w);

            categories[i] = cat;
        }
        return categories;
    };


    //
    m_productsView = ui->productsView;
    m_productsView->resize(800, 600);
    ProductsScene* pScene = new ProductsScene(m_productsView->width());
    pScene->setItems(p(55));
    m_productsView->setScene(pScene);

    qDebug() << "productsViewRect " << m_productsView->rect();

    m_categoriesView = ui->categoriesView;
    CategoriesScene* cScene = new CategoriesScene();
    cScene->setItems(c(10, m_categoriesView->width()));
    m_categoriesView->setScene(cScene);

    m_userPanelView = ui->userPanelView;
    UserPanelScene* uScene = new UserPanelScene();
    m_userPanelView->setScene(uScene);
}

NVKMainWindow::~NVKMainWindow()
{
    delete ui;
}

void NVKMainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() & Qt::Key_Escape)
    {
        close();
    }
}

Order* NVKMainWindow::order() const
{
    return m_order;
}
