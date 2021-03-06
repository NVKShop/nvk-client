#include "ProductSearchController.h"
#include <QMessageBox>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QDebug>

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

void ProductSearchController::searched()
{
    m_searchedAlready = true;
}

void ProductSearchController::setCategories(const QStringList &categories)
{
    QStandardItemModel* categoriesModel = new QStandardItemModel(categories.size(),1);

    for (int i = 0; i < categories.size(); ++i)
    {
        QStandardItem* cat = new QStandardItem(categories.at(i));
        cat->setCheckable(true);
        cat->setCheckState(Qt::Unchecked);

        categoriesModel->setItem(i, 0, cat);
    }
    QComboBox* cb = view()->searchCategoriesComboBox();
    cb->setModel(categoriesModel);
}

ProductSearchController::~ProductSearchController()
{
    delete m_productSearchWindow;
}

bool ProductSearchController::searchedAlready()
{
    return m_searchedAlready;
}
