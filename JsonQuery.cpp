#include "JsonQuery.h"

JsonQuery::JsonQuery(QObject *parent) : QObject(parent)
{

}

const QJsonDocument JsonQuery::getDocument() const
{
    return m_document;
}
