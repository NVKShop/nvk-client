#ifndef ADDRESS_H
#define ADDRESS_H

#include <QString>
#include <QJsonObject>

class Address
{
public:
    Address() = default;
    Address(const long& id, const QString& country, const QString& zip, const QString& street, const QString& hnum,
            const QString& city);

    QString country() const;
    QString zip() const;
    QString street() const;
    QString houseNumber() const;
    QString city() const;
    long id() const;

    void setCity(const QString& city);
    void setCountry(const QString& country);
    void setZip(const QString& zip);
    void setHouseNumber(const QString& num);
    void setStreet(const QString& street);
    void setId(const long& id);

    QJsonObject asJson() const;
private:
    QString m_country;
    QString m_zip;
    QString m_street;
    QString m_houseNumber;
    QString m_city;
    long m_id;
};

#endif // ADDRESS_H
