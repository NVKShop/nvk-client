#include "ProductSearch.h"

ProductSearch::ProductSearch(const QString &term, const QList<Category *> &categories,
                             const QPair<double, double> &priceInterval,
                             const QString &sortBy, const ProductSearch::Direction &direction)
    : m_searchTerm(term), m_searchCategories(categories),
      m_priceInterval(priceInterval), m_sortBy(sortBy), m_sortDirection(direction)
{
}

QString ProductSearch::searchTerm() const
{
    return m_searchTerm;
}

QList<Category*> ProductSearch::searchCategories() const
{
    return m_searchCategories;
}

QPair<double, double> ProductSearch::priceInterval() const
{
    return m_priceInterval;
}

QString ProductSearch::sortBy() const
{
    return m_sortBy;
}

ProductSearch::Direction ProductSearch::direction() const
{
    return m_sortDirection;
}

void ProductSearch::setSearchTerm(const QString &term)
{
    m_searchTerm = term;
}

void ProductSearch::setDirection(const ProductSearch::Direction &direction)
{
    m_sortDirection = direction;
}

void ProductSearch::setSortBy(const QString &sortby)
{
    m_sortBy = sortby;
}

void ProductSearch::setSearchCategories(const QList<Category *> &categories)
{
    m_searchCategories = categories;
}

void ProductSearch::setPriceInterval(const QPair<double, double> &priceInterval)
{
    m_priceInterval = priceInterval;
}

QJsonDocument ProductSearch::asJson() const
{
    return QJsonDocument();
}
