#include "frontend/widgets/ProductPreviewDialog.h"
#include "ui_productpreviewdialog.h"
#include <QFont>

ProductPreviewDialog::ProductPreviewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductPreviewDialog)
{
    ui->setupUi(this);
    connect(ui->closeButton, &QPushButton::clicked, this, &ProductPreviewDialog::close);
    connect(ui->addToCartButton, &QPushButton::clicked, this, &ProductPreviewDialog::addToCart);
    ui->productDescriptionLabel->setWordWrap(true);
    ui->productDescriptionLabel->setAlignment(Qt::AlignJustify);

    QPalette p(palette());
    setAutoFillBackground(true);
    p.setColor(QPalette::Background, QColor::fromRgb(0x42, 0x41, 0x3D));
    setPalette(p);

    QPalette pt(ui->productDescriptionLabel->palette());
    pt.setColor(QPalette::WindowText, QColor::fromRgb(0xFF, 0xCE,0x2B));
    ui->productDescriptionLabel->setPalette(pt);

    QPalette pn(ui->productNameLabel->palette());
    pn.setColor(QPalette::WindowText, QColor::fromRgb(0xF1, 0xED, 0xEA));
    ui->productNameLabel->setPalette(pn);

    QPalette pp(ui->productPriceLabel->palette());
    pp.setColor(QPalette::WindowText, QColor::fromRgb(0xEE, 0x75, 0x00));
    ui->productPriceLabel->setPalette(pp);

    QFont productNameFont;
    QFont productPriceFont;
    productPriceFont.setBold(true);
    productNameFont.setCapitalization(QFont::Capitalize);
    productNameFont.setBold(true);

#ifdef Q_OS_ANDROID
    productNameFont.setPointSize(20);
    productPriceFont.setPointSize(15);
#else
    productNameFont.setPointSize(25);
    productPriceFont.setPointSize(20);
#endif
    ui->productNameLabel->setFont(productNameFont);
    ui->productPriceLabel->setFont(productPriceFont);
    ui->closeButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
      "stop: 0 white, stop: 1 grey);"
      "border-style: solid;"
      "border-width: 2px;"
      "border-color: black;"
      "border-radius: 15px;}"));
    ui->addToCartButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
      "stop: 0 white, stop: 1 grey);"
      "border-style: solid;"
      "border-width: 2px;"
      "border-color: black;"
      "border-radius: 15px;}"));
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

QLabel* ProductPreviewDialog::productNameLabel() const
{
    return ui->productNameLabel;
}

QLabel* ProductPreviewDialog::productPriceLabel() const
{
    return ui->productPriceLabel;
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

