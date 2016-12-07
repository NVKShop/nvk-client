#include "frontend/widgets/PlaceOrderWindow.h"
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


    connect(ui->cancelButton, &QPushButton::clicked, this, &PlaceOrderWindow::reject);
    connect(ui->placeOrderButton, &QPushButton::clicked, this, &PlaceOrderWindow::placeOrderButtonClicked);
}

PlaceOrderWindow::~PlaceOrderWindow()
{
    delete ui;
}

void PlaceOrderWindow::setOrder(Order *order)
{
    m_order = order;
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
