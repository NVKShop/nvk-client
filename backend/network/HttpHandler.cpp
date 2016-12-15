#include "backend/network/HttpHandler.h"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QDebug>

HttpHandler::HttpHandler(const QUrl& url)
{
    m_HttpRequest= new QNetworkRequest(url);
}

QVariant HttpHandler::replyVar() const
{
    if (m_HttpReply->isFinished())
    {
        QVariant rply(m_HttpReply->readAll());

        return rply;
    }
    return QVariant();
}

/*JsonReply HttpHandler::post(const JsonRequest &msg)
{
    //sendRequest();
    QJsonParseError* err = new QJsonParseError;
    QJsonDocument doc = QJsonDocument::fromJson(reply()->readAll(), err);
    if (!err->errorString().isEmpty()) {
        qDebug() << err->errorString();
        return QJsonDocument();
    }
    QJsonDocument doc;
    JsonReply reply(doc);
    return reply;
}*/
