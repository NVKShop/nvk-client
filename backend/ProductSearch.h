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
        ASC,
        DESC
    };
    ProductSearch(const QString& term, const QList<Category*>& categories, const QPair<double, double>& priceInterval,
                  const QString& sortBy, const Direction& direction);

    ProductSearch() = default;

    void setSearchTerm(const QString& term);
    void setSearchCategories(const QList<Category*>& categories);
    void setPriceInterval(const QPair<double, double>& priceInterval);
    void setSortBy(const QString& sortby);
    void setDirection(const Direction& direction);

    QString searchTerm() const;
    QList<Category*> searchCategories() const;
    QPair<double, double> priceInterval() const;
    QString sortBy() const;
    Direction direction() const;

    QJsonDocument asJson() const;
private:

    QString m_searchTerm;
    QList<Category*> m_searchCategories;
    QPair<double, double> m_priceInterval;
    QString m_sortBy;
    Direction m_sortDirection;
};

#endif // PRODUCTSEARCH_H
