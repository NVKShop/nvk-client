#include "backend/network/JsonQuery.h"

JsonQuery::JsonQuery(QObject *parent) : QObject(parent)
{
}

QJsonDocument JsonQuery::document() const
{
    return m_document;
}
