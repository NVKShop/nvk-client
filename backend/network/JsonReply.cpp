#include "backend/network/JsonReply.h"
#include "backend/CategoryProperty.h"
#include "backend/ProductProperty.h"
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>
#include <QDebug>

JsonReply::JsonReply(const QJsonDocument &doc)
{
    m_document = doc;
    if (doc.isEmpty())
    {
        qDebug() << "fucking emptysomehow";
    }
}

QVector<Product*> JsonReply::products() const
{
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

        QJsonValue picByte = prod["picture"];
        QPixmap pic = QPixmap::fromImage(QImage((uchar*)picByte.toVariant().toByteArray().data(), 210, 66, QImage::Format_RGB888));
        //qDebug() << picByte.toVariant().toByteArray();
        /*if (pic.isNull())
        {
            pic = QPixmap(":/images/noImage.png");
        }*/

        ProductProperty properties(static_cast<long>(prod["id"].toInt()),
                prod["name"].toString(),
                prod["description"].toString(),
                prod["category"].toString(),
                prod["price"].toDouble());

        Product* p = new Product(pic,properties);
        prods.push_back(p);
    }

    return prods;
}

QVector<Category*> JsonReply::categories(const int &width) const
{
    QJsonArray jcatArray = m_document.array();
    if (jcatArray.isEmpty())
    {
        return QVector<Category*>();
    }
    QVector<Category*> cats;
    for (int i = 0; i < jcatArray.size(); ++i)
    {
        QJsonObject c = jcatArray[i].toObject();
        QPixmap img (":/images/catBg.png");
        CategoryProperty catProperty(static_cast<long>(c["categoryId"].toInt()), c["name"].toString(),
                static_cast<long>(c["parentId"].toInt()));
        Category* cat = new Category(img,catProperty,width);
        cats.push_back(cat);
    }

    return cats;
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
    QJsonObject juser = m_document.object();
    if (juser.isEmpty())
    {
        return nullptr;
    }

    QJsonObject juserAddress = juser["address"].toObject();

    User* user = new User();

    UserProperty properties;
    properties.setEmail(juser["email"].toString());
    properties.setLastName(juser["lastName"].toString());
    properties.setFirstName(juser["firstName"].toString());
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

QPixmap JsonReply::productPreviewPicture() const
{
    if (m_document.isEmpty())
    {
        return QPixmap();
    }

    QJsonValue picByte = m_document.object()["pictureAsByte"];
    QPixmap pic(picByte.toVariant().toByteArray());
    return pic;
}

QString JsonReply::productDescription() const
{
    if (m_document.isEmpty())
    {
        return QString();
    }

    QString description(m_document.object()["description"].toString());
    return description;
}

