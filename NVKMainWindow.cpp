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

    ui->productsView->resize(423, 801);
    ProductsScene* scene = new ProductsScene(ui->productsView->rect());

    // test items

    auto p = [](int count) -> QVector<Product*>
    {
        QVector<Product*> products;
        products.reserve(count);
        products.resize(count);

        for(int i = 0; i < count; ++i)
        {
            ProductProperty prop("Product " + QString::number(i), "desc", ProductProperty::IDK);
            Product* prod = new Product(QPixmap(":/noImage.png"), prop);
            products[i] = prod;
        }

        return  products;
    };

    scene->setItems(p(155));

    //
    m_ProductsView = new ProductsView(scene, ui->productsView);
    qDebug() << m_ProductsView->rect();
    connect(m_NetworkHandler, &NetworkHandler::readyRead, this, &NVKMainWindow::setReplyLabel);
}

NVKMainWindow::~NVKMainWindow()
{
    delete ui;
}

void NVKMainWindow::setReplyLabel(const QString &label)
{
    ui->replyLabel->setText(label);
    ui->replyLabel->adjustSize();
}

