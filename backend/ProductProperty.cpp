#include "backend/ProductProperty.h"

ProductProperty::ProductProperty(const QString &name, const QString &desc, const QString & cat, const double& price):
    Property(name), m_description(desc), m_category(cat), m_price(price)
{
}

QString ProductProperty::description() const
{
    return m_description;
}

QString ProductProperty::shortDescription() const
{
    return m_shortDescription;
}

QString ProductProperty::category() const
{
    return m_category;
}

double ProductProperty::price() const
{
    return m_price;
}

void ProductProperty::setShortDescription(const QString &desc)
{
    m_shortDescription = desc;
}
