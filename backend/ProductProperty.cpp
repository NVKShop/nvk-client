#include "backend/ProductProperty.h"

ProductProperty::ProductProperty(const QString &name, const QString &desc, const ProductProperty::Category& cat, const double& price):
    Property(name), m_description(desc), m_category(cat), m_price(price)
{
}

QString ProductProperty::description() const
{
    return m_description;
}

ProductProperty::Category ProductProperty::category() const
{
    return m_category;
}

double ProductProperty::price() const
{
    return m_price;
}
