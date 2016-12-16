#ifndef PROPERTY_H
#define PROPERTY_H
#include <QString>

class Property
{
public:
    Property(const long& id, const QString& name);
    Property() = default;
    QString name() const;
    void setName(const QString& name);
    long id() const;
    void setId(const long &id);
private:
    QString m_name;
    long m_id;
};

#endif // PROPERTY_H
