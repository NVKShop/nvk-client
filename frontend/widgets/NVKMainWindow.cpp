#include "frontend/widgets/NVKMainWindow.h"
#include "backend/network/HttpHandler.h"

#include "ui_nvkmainwindow.h"
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QScrollBar>
#include <QComboBox>
#include <QDebug>

NVKMainWindow::NVKMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NVKMainWindow), m_order(new Order())
{
    setWindowTitle("NVK Shop");
    ui->setupUi(this);

#ifdef Q_OS_ANDROID
    //Set sizes for Android
    QString barstyle =  "QScrollBar:horizontal {height: 7px;}" "QScrollBar:vertical {width: 9px;}";
    ui->productsView->verticalScrollBar()->setStyleSheet(barstyle);
    ui->categoriesView->verticalScrollBar()->setStyleSheet(barstyle);

#else
    QDesktopWidget* dw = QApplication::desktop();
    dw->availableGeometry(dw->primaryScreen());
    resize( dw->availableGeometry(dw->primaryScreen()).size());
#endif
    qDebug() << ui->productsView->width();
    setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->searchButton, &QPushButton::clicked, this, &NVKMainWindow::searchProductClicked);
    connect(ui->nextPageButton, &QPushButton::clicked, this, &NVKMainWindow::nextPage);
    connect(ui->previousPageButton, &QPushButton::clicked, this, &NVKMainWindow::previousPage);

    connect(ui->pageSizeComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &NVKMainWindow::pageSizeChanged);
    QPalette p(palette());
    setAutoFillBackground(true);
    p.setColor(QPalette::Background, QColor::fromRgb(0x42, 0x41, 0x3D));
    setPalette(p);

    QPalette pt(ui->productsInCategoryLabel->palette());
    pt.setColor(QPalette::WindowText, QColor::fromRgb(0xFF, 0xCE,0x2B));
    ui->productsInCategoryLabel->setPalette(pt);
    ui->pageSizeLabel->setPalette(pt);

    ui->searchButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                      "stop: 0 white, stop: 1 grey);"
                                                      "border-style: solid;"
                                                      "border-width: 2px;"
                                                      "border-color: black;"
                                                      "border-radius: 15px;}"));

    ui->previousPageButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                            "stop: 0 white, stop: 1 grey);"
                                                            "border-style: solid;"
                                                            "border-width: 2px;"
                                                            "border-color: black;"
                                                            "border-radius: 15px;}"));

    ui->nextPageButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                        "stop: 0 white, stop: 1 grey);"
                                                        "border-style: solid;"
                                                        "border-width: 2px;"
                                                        "border-color: black;"
                                                        "border-radius: 15px;}"));

}

void NVKMainWindow::setupViews()
{
    // test items

    //GET /listCategories
    /*HttpHandler handler(LIST_CATEGORIES_REQUEST);
    handler.sendRequest(QString());

    QJsonDocument replyDoc = QJsonDocument::fromBinaryData(handler.reply()->readAll());

    if (replyDoc.isNull())
    {
        //unable to fetch categories/ do something
    }

    JsonReply jreply (replyDoc);
    QVector<Category*> cats = jreply.categories();*/

    auto c = [](int count,const int w) ->QVector<Category*>
    {
        QVector<Category*> categories;
        categories.reserve(count);
        categories.resize(count);

        for (int i = 0; i < count; ++i)
        {
            CategoryProperty prop(0,QLatin1String("Category ") + QString::number(i),0);
            Category* cat = new Category(QPixmap(":/images/catBg.png"), prop, w);

            categories[i] = cat;
        }
        return categories;
    };



    auto p = [](int count) -> QVector<Product*>
    {
        QVector<Product*> products;
        products.reserve(count);
        products.resize(count);

        for(int i = 0; i < count; ++i)
        {
            ProductProperty prop(i,"Product " + QString::number(i),
                                 "This is a fucking description you retarded bitch. "
                                 "Can you get it? No? Great, because neither I. "
                                 "Well, it sucks, but that's it. "
                                 "I mean de mieert. What the crap should I write here so this retarded description gets longer and longer? I have no clue man sheiiiit.", "cat", 1);
            Product* prod = new Product(QPixmap(":/images/noImage.png"), prop);
            products[i] = prod;
        }

        return  products;
    };

    auto p1 = [](int count) -> QVector<Product*>
    {
        QVector<Product*> products;
        products.reserve(count);
        products.resize(count);

        for(int i = 0; i < count; ++i)
        {
            ProductProperty prop(i*2,"ProductCat1 " + QString::number(i),
                                 "This is a fckin product you dumbass","cat", 1);
            Product* prod = new Product(QPixmap(":/images/noImage.png"), prop);
            products[i] = prod;
        }

        return  products;
    };

    QVector<Category*> categories = c(6, ui->categoriesView->width() ); //
    QVector<Product*> c1p = p(40);
    QVector<Product*> c2p = p1(5);

    foreach (Product* prod, c1p) {
        m_categoryMapped.insert(categories.at(0), prod);
    }

    foreach (Product* prod, c2p) {
        m_categoryMapped.insert(categories.at(1), prod);
    }

    //
    m_productsView = ui->productsView;
    m_productsView->show();
    ProductsScene* pScene = new ProductsScene(m_productsView->width());
    m_productsView->setScene(pScene);
    pScene->setItems(m_categoryMapped.values(m_categoryMapped.firstKey()));

    m_categoriesView = ui->categoriesView;

    CategoriesScene* cScene = new CategoriesScene();
    cScene->setItems(categories);
    m_categoriesView->setScene(cScene);
    m_categoriesView->setCurrentCategory(categories.at(0));

    m_userPanelView = ui->userPanelView;
    UserPanelScene* uScene = new UserPanelScene();

    connect(uScene, &UserPanelScene::cartClicked, this, &NVKMainWindow::showCart);
    connect(uScene, &UserPanelScene::settingsClicked, this, &NVKMainWindow::showSettings);

    uScene->setSceneRect(0,0, m_userPanelView->width(), m_userPanelView->height());
    uScene->setupScene();
    uScene->setUserName(m_order->user()->properties().name());

    m_userPanelView->setScene(uScene);
    ui->productsInCategoryLabel->setText(QString::number(
                                             m_categoryMapped.values(m_categoriesView->currentCategory()).size())+ " products in this category");
    ui->productsInCategoryLabel->adjustSize();
}

NVKMainWindow::~NVKMainWindow()
{
    delete ui;
    delete m_categoriesView;
    delete m_order;
    delete m_productsView;
    delete m_userPanelView;
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

void NVKMainWindow::showEvent(QShowEvent *event)
{
#ifdef Q_OS_ANDROID
    showFullScreen();
#else
    show();
#endif
    setupViews();
    emit shown();
    QMainWindow::showEvent(event);
}

void NVKMainWindow::closeEvent(QCloseEvent *event)
{
    emit closing();
    QMainWindow::closeEvent(event);
}

void NVKMainWindow::categoryChanged(Category *newCategory)
{
    if (m_categoriesView->currentCategory() != newCategory) {
        m_categoriesView->setCurrentCategory(newCategory);
        ProductsScene* scene = static_cast<ProductsScene*>(m_productsView->scene());
        m_productsView->scrollToTop();

        //GET /productsByCategory?categoryId=<kategória id>&pageSize=<lap mérete>&pageNumber=<a lap sorszáma>

       /* QUrl productsByCatUrl ("productsByCategory?categoryId=" +
                               QString::number(newCategory->properties().id())+
                               "&pageSize=" + QString::number(ui->pageSizeComboBox->currentText().toInt())+
                               "&pageNumber=" + QString::number(m_currentPage));
        HttpHandler httpHandler(productsByCatUrl);
        httpHandler.sendRequest(QString());*/
        scene->setItems(m_categoryMapped.values(m_categoriesView->currentCategory()));

        ui->productsInCategoryLabel->setText( QString::number(
                                                  m_categoryMapped.values(m_categoriesView->currentCategory()).size()) + QLatin1String(" products in this category"));
        ui->productsInCategoryLabel->adjustSize();
    }
}

QList<Category*> NVKMainWindow::categories() const
{
    return m_categoryMapped.uniqueKeys();
}

UserPanelScene* NVKMainWindow::userPanelScene() const
{
    return qobject_cast<UserPanelScene*>(m_userPanelView->scene());
}

ProductsScene* NVKMainWindow::productsScene() const
{
    return qobject_cast<ProductsScene*>(m_productsView->scene());
}

CategoriesScene* NVKMainWindow::categoriesScene() const
{
    return qobject_cast<CategoriesScene*>(m_categoriesView->scene());
}

ProductsView* NVKMainWindow::productsView() const
{
    return m_productsView;
}

CategoriesView* NVKMainWindow::categoriesView() const
{
    return m_categoriesView;
}

QComboBox* NVKMainWindow::pageSizeCb() const
{
    return ui->pageSizeComboBox;
}

int NVKMainWindow::currentPage() const
{
    return m_currentPage;
}
