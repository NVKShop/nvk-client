#include "frontend/widgets/PlaceOrderWindow.h"
#include "ui_placeorderwindow.h"
#include <QShowEvent>

PlaceOrderWindow::PlaceOrderWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlaceOrderWindow)
{
    ui->setupUi(this);
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
