#include "backend/network/HttpHandler.h"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QDebug>

HttpHandler::HttpHandler(const QUrl& url)
{
    m_HttpRequest= new QNetworkRequest(url);
    //m_HttpRequest->setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
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

void HttpHandler::setUrl(const QUrl &url)
{
    m_HttpRequest = new QNetworkRequest(url);
}

const QString HttpHandler::DETAILED_PRODUCT_URL_STRING = QLatin1String("http://192.168.43.251:8080/nvk-integration/detailedProduct/%1");
const QString HttpHandler::LIST_CATEGORIES_URL_STRING = QLatin1String("http://192.168.43.251:8080/nvk-integration/listCategories");
const QString HttpHandler::ORDER_PLACEMENT_URL_STRING = QLatin1String("http://192.168.43.251:8080/nvk-integration/secured/orderPlacement");
const QString HttpHandler::PRODUCTS_BY_CATEGORY_URL_STRING = QLatin1String("http://192.168.43.251:8080/nvk-integration/productsByCategory?categoryId=%1&pageSize=%2&pageNumber=%3");
const QString HttpHandler::FORGOTTEN_PASSWORD_URL_STRING = QLatin1String("http://192.168.43.251:8080/nvk-integration/forgottenPassword?email=%1");
const QString HttpHandler::USER_LOGIN_INFORMATIONS_QUERY_URL_STRING = QLatin1String("http://192.168.43.251:8080/nvk-integration/secured/userInformation");

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

