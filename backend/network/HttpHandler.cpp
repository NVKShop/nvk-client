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

const QString HttpHandler::DETAILED_PRODUCT_URL_STRING = QLatin1String("http://192.168.43.251:8080/nvk-web/detailedProduct/%1");
const QString HttpHandler::LIST_CATEGORIES_URL_STRING = QLatin1String("http://192.168.43.251:8080/nvk-web/listCategories");
const QString HttpHandler::ORDER_PLACEMENT_URL_STRING = QLatin1String("http://192.168.43.251:8080/nvk-web/orderPlacement");
const QString HttpHandler::PRODUCTS_BY_CATEGORY_URL_STRING = QLatin1String("http://192.168.43.251:8080/productsByCategory?categoryId=%1&pageSize=%2&pageNumber=%3");
const QString HttpHandler::FORGOTTEN_PASSWORD_URL_STRING = QLatin1String("http://192.168.43.251:8080/nvk-web/forgottenPassword?email=%1");


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

