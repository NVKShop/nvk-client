#ifndef PRODUCTPROPERTY_H
#define PRODUCTPROPERTY_H

#include "backend/Property.h"

class ProductProperty : public Property
{
public:

    ProductProperty(const long& id, const QString& name, const QString& desc, const QString& cat, const double& price);

    void setShortDescription(const QString& desc);
    QString description() const;
    QString shortDescription() const;
    QString category() const;
    double price() const;
private:
    QString m_description;
    QString m_shortDescription;
    QString m_category;
    double m_price;
};

#endif // PRODUCTPROPERTY_H
