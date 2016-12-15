#include "backend/Address.h"

Address::Address(const QString &country, const QString &zip, const QString &street, const QString &hnum, const QString &city)
    : m_country(country), m_zip(zip), m_street(street), m_houseNumber(hnum), m_city(city)
{
}

QString Address::country() const
{
    return m_country;
}

QString Address::city() const
{
    return m_city;
}

QString Address::houseNumber() const
{
    return m_houseNumber;
}

QString Address::zip() const
{
    return m_zip;
}

QString Address::street() const
{
    return m_street;
}

void Address::setCity(const QString &city)
{
    m_city = city;
}

void Address::setCountry(const QString &country)
{
    m_country = country;
}

void Address::setZip(const QString &zip)
{
    m_zip = zip;
}

void Address::setStreet(const QString &street)
{
    m_street = street;
}

void Address::setHouseNumber(const QString &num)
{
    m_houseNumber = num;
}

QJsonObject Address::asJson() const
{
    QJsonObject address;

    QJsonValue jcountry (m_country);
    QJsonValue jcity(m_city);
    QJsonValue jzip (m_zip);
    QJsonValue jhnumber(m_houseNumber);
    QJsonValue jstreet(m_street);

    address["country"] = jcountry;
    address["city"] = jcity;
    address["zip"] = jzip;
    address["street"] = jstreet;
    address["houseNumber"] = jhnumber;

    return address;
}
