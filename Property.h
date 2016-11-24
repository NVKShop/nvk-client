#ifndef PROPERTY_H
#define PROPERTY_H
#include <QString>

class Property
{
public:
    Property(const QString& name);
    Property() = default;
    QString name() const;
private:
    QString m_name;
};

#endif // PROPERTY_H
