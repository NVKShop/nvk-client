#include "NVKMainWindow.h"
#include "ui_nvkmainwindow.h"

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
    //Desktop sizes
#endif

    ui->productsView->resize(500,500);
    ProductsScene* scene = new ProductsScene(ui->productsView->rect());

    //

    auto p = []() -> QVector<Product*> {
            QVector<Product*> products;
            products.reserve(5);
            products.resize(5);

            Product* prod = new Product(QPixmap(":/noImage.png"));

            for(int i = 0; i < 5; ++i)
    {
        products[i] = prod;
    }

    return  products;
};
scene->setItems(p());

//
m_ProductsView = new ProductsView(scene, ui->productsView);
 qDebug() << m_ProductsView->rect();
// connect(ui->requestThingsButton, &QPushButton::clicked, m_NetworkHandler, &NetworkHandler::sendRequest);
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

