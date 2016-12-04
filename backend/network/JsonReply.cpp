#include "backend/network/JsonReply.h"

JsonReply::JsonReply(const QJsonDocument &doc)
{
    m_document = doc;
}

QVector<Product*> JsonReply::getProducts() const
{
    // products from m_document

    return QVector<Product*>();
}

User* JsonReply::getUser() const
{
    if (m_document.isEmpty())
    {
        return nullptr;
    }

    User* user = new User();

    UserProperty properties;

    user->setProperties(properties);
    return user;
}
