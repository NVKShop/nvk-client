#include "NVKMainWindow.h"
#include "ui_nvkmainwindow.h"

NVKMainWindow::NVKMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NVKMainWindow),
    m_NetworkHandler(new NetworkHandler)
{
    ui->setupUi(this);
#ifdef Q_OS_ANDROID
    //Set sizes for Android

#else
    //Desktop sizes
#endif

    ProductsScene* scene = new ProductsScene(ui->productsView->rect());
    m_ProductsView = new ProductsView(scene, ui->productsView);
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

