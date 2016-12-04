#include "frontend/widgets/ProductPreviewDialog.h"
#include "ui_productpreviewdialog.h"

ProductPreviewDialog::ProductPreviewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductPreviewDialog)
{
    ui->setupUi(this);
}

ProductPreviewDialog::~ProductPreviewDialog()
{
    delete ui;
}
