#include "NVKMainWindow.h"
#include "ui_nvkmainwindow.h"
#include <QDesktopWidget>
NVKMainWindow::NVKMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NVKMainWindow),
    m_NetworkHandler(new NetworkHandler)
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

    //ui->productsView->resize(423, 801);
    qDebug() << ui->productsView->width();

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


    //
    m_ProductsView = ui->productsView;
    ProductsScene* scene = new ProductsScene(m_ProductsView->rect());
    scene->setItems(p(55));

    m_ProductsView->setScene(scene);

    qDebug() << "productsViewRect " << m_ProductsView->rect();
    connect(m_NetworkHandler, &NetworkHandler::readyRead, this, &NVKMainWindow::setReplyLabel);
}

NVKMainWindow::~NVKMainWindow()
{
    delete ui;
}

void NVKMainWindow::setReplyLabel(const QString &label)
{

}

