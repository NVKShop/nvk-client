#ifndef PRODUCTPROPERTY_H
#define PRODUCTPROPERTY_H

#include "backend/Property.h"

class ProductProperty : public Property
{
public:
    enum Category {
        IDK,
        SOMETHING
    };
    ProductProperty(const QString& name, const QString& desc, const Category& cat, const double& price);

    QString description() const;
    Category category() const;
    double price() const;
private:
    QString m_description;
    Category m_category;
    double m_price;
};

#endif // PRODUCTPROPERTY_H
