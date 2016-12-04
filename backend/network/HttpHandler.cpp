#include "backend/network/HttpHandler.h"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QDebug>

HttpHandler::HttpHandler(const QUrl& url)
{
    m_HttpRequest= new QNetworkRequest(url);
}

QJsonDocument HttpHandler::post(const QString &msg)
{
    sendRequest(msg);
    QJsonParseError* err = new QJsonParseError;
    QJsonDocument doc = QJsonDocument::fromJson(reply()->readAll(), err);
    if (!err->errorString().isEmpty()) {
        qDebug() << err->errorString();
        return QJsonDocument();
    }
    return doc;
}
