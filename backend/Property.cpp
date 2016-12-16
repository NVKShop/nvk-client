#include "backend/Property.h"

Property::Property(const long &id, const QString &name) : m_name(name), m_id(id)
{
}

QString Property::name() const
{
    return m_name;
}

void Property::setName(const QString &name)
{
    m_name = name;
}

long Property::id() const
{
    return m_id;
}

void Property::setId(const long &id)
{
    m_id = id;
}
