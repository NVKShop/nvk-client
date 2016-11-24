#include "Property.h"

Property::Property(const QString &name) : m_name(name)
{
}

QString Property::name() const
{
    return m_name;
}
