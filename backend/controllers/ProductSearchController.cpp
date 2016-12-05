#include "ProductSearchController.h"

ProductSearchController::ProductSearchController(QObject *parent) : QObject(parent),
    m_productSearchWindow(new ProductSearchWindow)
{
}

ProductSearchWindow* ProductSearchController::view() const
{
    return m_productSearchWindow;
}
