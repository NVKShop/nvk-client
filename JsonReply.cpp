#include "JsonReply.h"

JsonReply::JsonReply(const QJsonDocument &doc)
{
    m_document = doc;
}

QVector<Product*> JsonReply::getProducts() const
{
    return QVector<Product*>();
}

User* JsonReply::getUser() const
{
    if (m_document.isEmpty())
    {
        return nullptr;
    }


    return nullptr;
}
