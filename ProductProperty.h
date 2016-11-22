#ifndef PRODUCTPROPERTY_H
#define PRODUCTPROPERTY_H

#include "Property.h"

class ProductProperty : public Property
{
public:
    enum Category {
        IDK,
        SOMETHING
    };
    ProductProperty(const QString& name, const QString& desc, const Category& cat);

    QString m_description;
    Category m_category;
};

#endif // PRODUCTPROPERTY_H
