#include "CategoryProperty.h"
#include <QString>

CategoryProperty::CategoryProperty(const long& id, const QString& name, const long& parentId):
    Property(id, name), m_parentId(parentId)
{
}
