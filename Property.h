#ifndef PROPERTY_H
#define PROPERTY_H
#include <QString>

class Property
{
public:
    Property(const QString& name);
    Property() = default;
    QString m_name;
};

#endif // PROPERTY_H
