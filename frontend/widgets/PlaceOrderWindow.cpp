#include "frontend/widgets/PlaceOrderWindow.h"
#include "backend/Cart.h"
#include "ui_placeorderwindow.h"
#include <QShowEvent>
#include <QPalette>
#include <QColor>
#include <QIntValidator>
#include <QSpinBox>

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
    ui->cartTableWidget->horizontalHeader()->setStretchLastSection(true);

    connect(ui->resetCartButton, &QPushButton::clicked, this, &PlaceOrderWindow::resetCart);
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
    QFont tableFont;
    tableFont.setBold(true);
    tableFont.setPointSize(13);

    ui->cartTableWidget->clearContents();
    foreach (Product* prod, m_order->user()->cart()->products()) {
        QTableWidgetItem* nameItem = new QTableWidgetItem;
        QTableWidgetItem* priceItem = new QTableWidgetItem;
        QSpinBox* countSpinBox = new QSpinBox();
        countSpinBox->setValue(prod->quantityInCart());

        countSpinBox->setStyleSheet(QLatin1String("QSpinBox::up-button {width: 40px;  height: 40px}"
                                                  "QSpinBox::down-button {width: 40px; height: 40px}"));
        countSpinBox->resize(countSpinBox->width(), 140);
        connect(countSpinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &PlaceOrderWindow::cartCellChangedSlot);
        nameItem->setFont(tableFont);
        priceItem->setFont(tableFont);

        priceItem->setText(QString::number(prod->properties().price())+QLatin1String(" HUF"));
        priceItem->setFlags(priceItem->flags() & ~Qt::ItemIsEditable);

        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
        nameItem->setText(prod->properties().name());
        ui->cartTableWidget->setItem(row, 0, nameItem);
        ui->cartTableWidget->setItem(row, 1, priceItem);
        ui->cartTableWidget->setCellWidget(row, 2, countSpinBox);
        ui->cartTableWidget->resizeRowToContents(row);

        row++;
        totalPrice+= prod->properties().price() * prod->quantityInCart();
    }
    m_order->setOrderTotalPrice(totalPrice);
    ui->priceLabel->setText(QString::number(totalPrice)+ QLatin1String(" HUF"));
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

Order* PlaceOrderWindow::order() const
{
    return m_order;
}

QTableWidget* PlaceOrderWindow::cartTableWidget() const
{
    return ui->cartTableWidget;
}

void PlaceOrderWindow::cartCellChangedSlot(int val)
{
    QSpinBox* ssender = qobject_cast<QSpinBox*> (sender());
    int row = 0;
    for (; row < ui->cartTableWidget->rowCount();++row)
    {
        if (ui->cartTableWidget->cellWidget(row, 2) == ssender)
        {
            break;
        }
    }

    emit cartCellChanged(row, val);
}
