#include "ProductProperty.h"

ProductProperty::ProductProperty(const QString &name, const QString &desc, const ProductProperty::Category& cat):
    Property(name), m_description(desc), m_category(cat)
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
