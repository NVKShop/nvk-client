#include "ProductPreviewController.h"

ProductPreviewController::ProductPreviewController(QObject *parent) : QObject(parent),
    m_productPreviewDialog(new ProductPreviewDialog)
{  
    connect(m_productPreviewDialog, &ProductPreviewDialog::addToCart, this, &ProductPreviewController::emitAddToCart);
}

ProductPreviewDialog* ProductPreviewController::view() const
{
    return m_productPreviewDialog;
}

void ProductPreviewController::setProduct(Product* product)
{
    const ProductProperty& prop = product->properties();
    m_productPreviewDialog->descriptionLabel()->setText(prop.description());
    m_productPreviewDialog->descriptionLabel()->adjustSize();

    m_productPreviewDialog->previewLabel()->setPixmap(product->originalPixmap());
    m_productPreviewDialog->previewLabel()->adjustSize();
    m_product = product;

    m_productPreviewDialog->productNameLabel()->setText(prop.name());
    m_productPreviewDialog->productPriceLabel()->setText("Price: " + QString::number(prop.price())+ " HUF");
}

Product* ProductPreviewController::product() const
{
    return m_product;
}

void ProductPreviewController::emitAddToCart()
{
    emit addToCart(product());
}

ProductPreviewController::~ProductPreviewController()
{
    delete m_productPreviewDialog;
}


