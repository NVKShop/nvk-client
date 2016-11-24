#include "NVKMainWindow.h"
#include "ui_nvkmainwindow.h"
#include <QDesktopWidget>
NVKMainWindow::NVKMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NVKMainWindow),
    m_networkHandler(new NetworkHandler)
{
    setWindowTitle("NVK Shop");
    ui->setupUi(this);
#ifdef Q_OS_ANDROID
    //Set sizes for Android

#else
    QDesktopWidget* dw = QApplication::desktop();
    dw->availableGeometry(dw->primaryScreen());

    resize( dw->availableGeometry(dw->primaryScreen()).size());
    //Desktop sizes
#endif

    qDebug() << ui->productsView->width();

    setupViews();

    qDebug() << "productsViewRect " << m_productsView->rect();
    connect(m_networkHandler, &NetworkHandler::readyRead, this, &NVKMainWindow::setReplyLabel);
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
            ProductProperty prop("Product " + QString::number(i), "Description", ProductProperty::IDK);
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
    ProductsScene* pScene = new ProductsScene(m_productsView->rect());
    pScene->setItems(p(55));
    m_productsView->setScene(pScene);

    m_categoriesView = ui->categoriesView;
    CategoriesScene* cScene = new CategoriesScene(m_categoriesView->rect());
    cScene->setItems(c(10, cScene->width()));
    m_categoriesView->setScene(cScene);

    m_userPanelView = ui->userPanelView;
    UserPanelScene* uScene = new UserPanelScene(m_userPanelView->rect());
    m_userPanelView->setScene(uScene);
}

NVKMainWindow::~NVKMainWindow()
{
    delete ui;
}

void NVKMainWindow::setReplyLabel(const QString &label)
{

}

