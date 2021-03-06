#include "ProductPreviewController.h"

ProductPreviewController::ProductPreviewController(QObject *parent) : QObject(parent),
    m_productPreviewDialog(new ProductPreviewDialog)
{  
    connect(m_productPreviewDialog, &ProductPreviewDialog::addToCart, this, &ProductPreviewController::emitAddToCart);
    connect(m_productPreviewDialog, &ProductPreviewDialog::addToCart, m_productPreviewDialog, &ProductPreviewDialog::close);
    connect(m_productPreviewDialog, &ProductPreviewDialog::addToCart, this, &ProductPreviewController::addedToCart);
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

    m_product = product;

    m_productPreviewDialog->productNameLabel()->setText(prop.name());
    m_productPreviewDialog->productPriceLabel()->setText("Price: " + QString::number(prop.price())+ " HUF");
}

Product* ProductPreviewController::product() const
{
    return m_product;
}
#include <QDebug>

void ProductPreviewController::emitAddToCart()
{
    product()->addedToCart();
    emit addToCart(product());
}

ProductPreviewController::~ProductPreviewController()
{
    delete m_productPreviewDialog;
}

void ProductPreviewController::setPixmap(const QPixmap &pixmap)
{
    product()->setOriginalPixmap(pixmap);

    m_productPreviewDialog->previewLabel()->setPixmap(product()->originalPixmap());
    m_productPreviewDialog->previewLabel()->adjustSize();
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(10);
    shadow->setOffset(10.0);
    shadow->setColor(Qt::black);
    m_productPreviewDialog->previewLabel()->setGraphicsEffect(shadow);
}


