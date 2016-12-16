#include "backend/network/JsonReply.h"
#include "backend/ProductProperty.h"
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>

JsonReply::JsonReply(const QJsonDocument &doc)
{
    m_document = doc;
}

QVector<Product*> JsonReply::products() const
{
    // products from m_document

    QJsonObject jmainobj = m_document.object();

    QJsonArray jproducts = jmainobj["products"].toArray();

    if (jproducts.isEmpty())
    {
        return QVector<Product*>();
    }
    QVector<Product*> prods;

    for (int i = 0; i < jproducts.size(); ++i)
    {

        QJsonObject prod = jproducts[i].toObject();

        QPixmap productImage;
        ProductProperty properties(static_cast<long>(prod["id"].toInt()),
                prod["name"].toString(),
                prod["description"].toString(),
                prod["category"].toString(),
                prod["price"].toDouble());

        Product* p = new Product(productImage,properties);
        prods.push_back(p);
    }

    return prods;
}

bool JsonReply::nextPageExists() const
{
    QJsonObject jmainobj = m_document.object();
    QJsonValue npe = jmainobj["nextPageExists"];
    return npe.toBool(false);
}

bool JsonReply::previousPageExists() const
{
    QJsonObject jmainobj = m_document.object();
    QJsonValue ppe = jmainobj["previousPageExists"];
    return ppe.toBool(false);
}

User* JsonReply::user() const
{
    if (m_document.isEmpty())
    {
        return nullptr;
    }

    QJsonObject mainObj = m_document.object();
    QJsonObject juser = mainObj["user"].toObject();
    if (juser.isEmpty())
    {
        return nullptr;
    }

    QJsonObject juserAddress = juser["address"].toObject();

    User* user = new User();

    UserProperty properties;
    properties.setId(static_cast<long>(juser["id"].toInt()));
    properties.setEmail(juser["email"].toString());
    properties.setLastName(juser["lastName"].toString());
    properties.setFirstName(juser["firstName"].toString());
    properties.setPassword(juser["password"].toString());
    properties.setName(juser["name"].toString());
    properties.setRole(static_cast<UserProperty::Role>(juser["role"].toInt()));
    properties.setPhoneNumber(juser["phoneNumber"].toString());

    Address uaddress;
    uaddress.setCity(juserAddress["city"].toString());
    uaddress.setCountry(juserAddress["country"].toString());
    uaddress.setStreet(juserAddress["street"].toString());
    uaddress.setZip(juserAddress["zip"].toString());
    uaddress.setHouseNumber(juserAddress["houseNumber"].toString());

    properties.setAddress(uaddress);

    user->setProperties(properties);
    return user;
}
