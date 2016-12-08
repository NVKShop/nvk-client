#include "frontend/widgets/PlaceOrderWindow.h"
#include "backend/Cart.h"
#include "ui_placeorderwindow.h"
#include <QShowEvent>
#include <QPalette>
#include <QColor>

PlaceOrderWindow::PlaceOrderWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlaceOrderWindow)
{
    ui->setupUi(this);
    QPalette p(palette());
    setAutoFillBackground(true);
    p.setColor(QPalette::Background, QColor::fromRgb(0x42, 0x41, 0x3D));
    setPalette(p);
    ui->cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                      "stop: 0 white, stop: 1 grey);"
                                                      "border-style: solid;"
                                                      "border-width: 2px;"
                                                      "border-color: black;"
                                                      "border-radius: 15px;}"));

    ui->placeOrderButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                      "stop: 0 white, stop: 1 grey);"
                                                      "border-style: solid;"
                                                      "border-width: 2px;"
                                                      "border-color: black;"
                                                      "border-radius: 15px;}"));

    ui->resetCartButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                     "stop: 0 white, stop: 1 grey);"
                                                     "border-style: solid;"
                                                     "border-width: 2px;"
                                                     "border-color: black;"
                                                     "border-radius: 15px;}"));

    QPalette pt(ui->totalPriceLabel->palette());
    pt.setColor(QPalette::WindowText, QColor::fromRgb(0xFF, 0xCE,0x2B));
    ui->totalPriceLabel->setPalette(pt);
    ui->priceLabel->setPalette(pt);

    QFont priceFont;
    priceFont.setPointSize(20);
    ui->totalPriceLabel->setFont(priceFont);

    priceFont.setBold(true);
    priceFont.setPointSize(18);
    ui->priceLabel->setFont(priceFont);


    connect(ui->cancelButton, &QPushButton::clicked, this, &PlaceOrderWindow::reject);
    connect(ui->placeOrderButton, &QPushButton::clicked, this, &PlaceOrderWindow::placeOrderButtonClicked);
}

PlaceOrderWindow::~PlaceOrderWindow()
{
    delete ui;
}
#include <QDebug>

void PlaceOrderWindow::setOrder(Order *order)
{
    m_order = order;
    int row = 0;
    double totalPrice = 0;
    ui->cartTableWidget->setRowCount(m_order->user()->cart()->products().size());
    foreach (Product* prod, m_order->user()->cart()->products()) {
        QTableWidgetItem* nameItem = new QTableWidgetItem;
        QTableWidgetItem* countItem = new QTableWidgetItem("1");
        QTableWidgetItem* priceItem = new QTableWidgetItem;

        priceItem->setText(QString::number(prod->properties().price())+" HUF");
        priceItem->setFlags(priceItem->flags() & ~Qt::ItemIsEditable);

        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
        nameItem->setText(prod->properties().name());
        ui->cartTableWidget->setItem(row, 0, nameItem);
        ui->cartTableWidget->setItem(row, 1, priceItem);
        ui->cartTableWidget->setItem(row, 2, countItem);
        row++;

        totalPrice+= prod->properties().price();
    }
    ui->priceLabel->setText(QString::number(totalPrice)+ " HUF");
    ui->cartTableWidget->resizeColumnsToContents();
}

void PlaceOrderWindow::showEvent(QShowEvent *e)
{
#ifdef Q_OS_ANDROID
    showFullScreen();
#else
    show();
#endif
    QDialog::showEvent(e);
}
