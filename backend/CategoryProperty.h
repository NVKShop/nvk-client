#ifndef CATEGORYPROPERTY_H
#define CATEGORYPROPERTY_H

#include "backend/Property.h"
class CategoryProperty : public Property
{
public:
    CategoryProperty(const long& id, const QString& name, const long& parentId);

private:
    long m_parentId;
};


#endif // CATEGORYPROPERTY_H
