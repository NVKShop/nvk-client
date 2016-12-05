#include "frontend/widgets/NVKMainWindow.h"
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
    setupViews();

    CategoriesScene* scene = static_cast<CategoriesScene*>(m_categoriesView->scene());
    connect(scene, &CategoriesScene::selectionChangedNew, this, &NVKMainWindow::categoryChanged);
    connect(ui->searchButton, &QPushButton::clicked, this, &NVKMainWindow::searchProductClicked);

    ProductsScene* pscene = static_cast<ProductsScene*>(m_productsView->scene());
    connect(pscene, &ProductsScene::productDoubleClicked, this, &NVKMainWindow::productDoubleClicked);
}

void NVKMainWindow::setupViews()
{
    // test items

    auto c = [](int count,const int w) ->QVector<Category*>
    {
        QVector<Category*> categories;
        categories.reserve(count);
        categories.resize(count);

        for (int i = 0; i < count; ++i)
        {
            Property prop("Category " + QString::number(i));
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
            ProductProperty prop("Product " + QString::number(i), "This is a fckin product you dumbass", ProductProperty::IDK, 1);
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
            ProductProperty prop("ProductCat1 " + QString::number(i), "This is a fckin product you dumbass", ProductProperty::IDK, 1);
            Product* prod = new Product(QPixmap(":/images/noImage.png"), prop);
            products[i] = prod;
        }

        return  products;
    };

    QVector<Category*> categories = c(3, 800 ); //
    QVector<Product*> c1p = p(10);
    QVector<Product*> c2p = p1(5);

    foreach (Product* prod, c1p) {
        m_categoryMapped.insert(categories.at(0), prod);
    }

    foreach (Product* prod, c2p) {
        m_categoryMapped.insert(categories.at(1), prod);
    }

    //
    m_productsView = ui->productsView;
    m_productsView->resize(800, 600);
    ProductsScene* pScene = new ProductsScene(m_productsView->width());
    pScene->setItems(m_categoryMapped.values(m_categoryMapped.firstKey()));
    m_productsView->setScene(pScene);

    qDebug() << "productsViewRect " << m_productsView->rect();

    m_categoriesView = ui->categoriesView;
    qDebug() << "catViewRect " << m_categoriesView->rect();

    CategoriesScene* cScene = new CategoriesScene();
    cScene->setItems(categories);
    m_categoriesView->setScene(cScene);

    m_userPanelView = ui->userPanelView;
    UserPanelScene* uScene = new UserPanelScene();
    uScene->setSceneRect(0,0, 800, 100);
    uScene->setUserName("Retarded Bitch");

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

void NVKMainWindow::showEvent(QShowEvent *event)
{
#ifdef Q_OS_ANDROID
    showFullScreen();
#else
    show();
#endif
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
        qDebug() << "new category selected";
        //fill productsview
        ProductsScene* scene = static_cast<ProductsScene*>(m_productsView->scene());
        scene->setItems(m_categoryMapped.values(m_categoriesView->currentCategory()));
        m_productsView->scrollToTop();
    }
}
