#include "ProductSearch.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

ProductSearch::ProductSearch(const QString &term, const QStringList &categories,
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

QStringList ProductSearch::searchCategories() const
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

void ProductSearch::setSearchCategories(const QStringList &categories)
{
    m_searchCategories = categories;
}

void ProductSearch::setPriceInterval(const QPair<double, double> &priceInterval)
{
    m_priceInterval = priceInterval;
}

int ProductSearch::page() const
{
    return m_page;
}

int ProductSearch::pageSize() const
{
    return m_pageSize;
}

QJsonDocument ProductSearch::asJson() const
{
    QJsonDocument doc;

    QJsonObject jsearchObj;
    QJsonValue jsearchTerm(m_searchTerm);
    QJsonValue jsortBy(m_sortBy);
    QJsonValue jsortDirection(static_cast<int>(m_sortDirection));
    QJsonValue jpriceFrom(m_priceInterval.first);
    QJsonValue jpriceTo(m_priceInterval.second);
    QJsonArray jsearchCategories;

    foreach (const QString& cat, m_searchCategories) {
        QJsonValue jcat(cat);
        jsearchCategories.append(jcat);
    }

    jsearchObj["searchTerm"] = jsearchTerm;
    jsearchObj["sortBy"] = jsortBy;
    jsearchObj["direction"] = jsortDirection;
    jsearchObj["priceFrom"] = jpriceFrom;
    jsearchObj["priceTo"] = jpriceTo;
    jsearchObj["categories"] = jsearchCategories;

    doc.setObject(jsearchObj);
    return doc;
}
