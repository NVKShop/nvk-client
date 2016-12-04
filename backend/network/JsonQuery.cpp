#include "backend/network/JsonQuery.h"

JsonQuery::JsonQuery(QObject *parent) : QObject(parent)
{

}

QJsonDocument JsonQuery::getDocument() const
{
    return m_document;
}
