#include "ProductSearchController.h"
#include <QMessageBox>

ProductSearchController::ProductSearchController(QObject *parent) : QObject(parent),
    m_productSearchWindow(new ProductSearchWindow)
{
    connect(m_productSearchWindow, &ProductSearchWindow::search, this, &ProductSearchController::search);
    connect(this, &ProductSearchController::searchDataOk, m_productSearchWindow, &ProductSearchWindow::close);
}

ProductSearchWindow* ProductSearchController::view() const
{
    return m_productSearchWindow;
}

void ProductSearchController::search()
{
    if (m_productSearchWindow->searchTerm().isEmpty())
    {
        QMessageBox::warning(0, "Product search error", "Error, search term must be specified!", QMessageBox::Ok);
    }
    else
    {
        ProductSearch* productSearch = new ProductSearch;

        productSearch->setDirection(static_cast<ProductSearch::Direction>(m_productSearchWindow->direction()));
        productSearch->setPriceInterval(m_productSearchWindow->priceInterval());
        productSearch->setSearchTerm(m_productSearchWindow->searchTerm());
        productSearch->setSortBy(m_productSearchWindow->sortBy());
        productSearch->setSearchCategories(m_productSearchWindow->categories());

        emit searchDataOk();
        emit searchProduct(productSearch);
    }
}
