#include "ProductPreviewController.h"

ProductPreviewController::ProductPreviewController(QObject *parent) : QObject(parent),
    m_productPreviewDialog(new ProductPreviewDialog)
{
}

ProductPreviewDialog* ProductPreviewController::view() const
{
    return m_productPreviewDialog;
}
