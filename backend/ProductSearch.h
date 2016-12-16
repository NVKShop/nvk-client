#ifndef PRODUCTSEARCH_H
#define PRODUCTSEARCH_H
#include <QString>
#include <QList>
#include <QPair>
#include "backend/graphics_items/Category.h"
#include <QJsonDocument>

class ProductSearch
{
public:

    enum Direction
    {
        ASC = 0,
        DESC
    };
    ProductSearch(const QString& term, const QStringList& categories, const QPair<double, double>& priceInterval,
                  const QString& sortBy, const Direction& direction);

    ProductSearch() = default;

    void setSearchTerm(const QString& term);
    void setSearchCategories(const QStringList &categories);
    void setPriceInterval(const QPair<double, double>& priceInterval);
    void setSortBy(const QString& sortby);
    void setDirection(const Direction& direction);

    QString searchTerm() const;
    QStringList searchCategories() const;
    QPair<double, double> priceInterval() const;
    QString sortBy() const;
    Direction direction() const;
    int page() const;
    int pageSize() const;

    QJsonDocument asJson() const;
private:

    QString m_searchTerm;
    QStringList m_searchCategories;
    QPair<double, double> m_priceInterval;
    QString m_sortBy;
    Direction m_sortDirection;
    int m_page;
    int m_pageSize;
};

#endif // PRODUCTSEARCH_H
