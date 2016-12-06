#include "frontend/widgets/ProductPreviewDialog.h"
#include "ui_productpreviewdialog.h"

ProductPreviewDialog::ProductPreviewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductPreviewDialog)
{
    ui->setupUi(this);
    connect(ui->closeButton, &QPushButton::clicked, this, &ProductPreviewDialog::close);
    connect(ui->addToCartButton, &QPushButton::clicked, this, &ProductPreviewDialog::addToCart);
    ui->productDescriptionLabel->setWordWrap(true);
    ui->productDescriptionLabel->setAlignment(Qt::AlignJustify);
}

ProductPreviewDialog::~ProductPreviewDialog()
{
    delete ui;
}

QLabel* ProductPreviewDialog::descriptionLabel() const
{
    return ui->productDescriptionLabel;
}

QLabel* ProductPreviewDialog::previewLabel() const
{
    return ui->productPreviewImageLabel;
}

void ProductPreviewDialog::showEvent(QShowEvent *e)
{
#ifdef Q_OS_ANDROID
    showFullScreen();
#else
    show();
#endif
    QDialog::showEvent(e);
}

