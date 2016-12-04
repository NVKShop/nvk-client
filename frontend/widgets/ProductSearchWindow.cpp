#include "ProductSearchWindow.h"
#include "ui_productsearchwindow.h"

ProductSearchWindow::ProductSearchWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductSearchWindow)
{
    ui->setupUi(this);
}

ProductSearchWindow::~ProductSearchWindow()
{
    delete ui;
}
