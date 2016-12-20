#ifndef HTTPHANDLER_H
#define HTTPHANDLER_H
#include "NetworkHandler.h"
#include "backend/network/JsonReply.h"
#include "backend/network/JsonRequest.h"

class QUrl;
class QJsonDocument;
class QNetworkReply;
class HttpHandler : public NetworkHandler
{
    Q_OBJECT
public:
    HttpHandler(const QUrl& url);
    HttpHandler() = default;
    QVariant replyVar() const;
    void setUrl(const QUrl& url);
    static const QString DETAILED_PRODUCT_URL_STRING;
    static const QString LIST_CATEGORIES_URL_STRING;
    static const QString ORDER_PLACEMENT_URL_STRING;
    static const QString PRODUCTS_BY_CATEGORY_URL_STRING;
    static const QString FORGOTTEN_PASSWORD_URL_STRING;
    static const QString USER_LOGIN_INFORMATIONS_QUERY_URL_STRING;
    static const QString PRODUCT_SEARCH_URL_STRING;
public Q_SLOTS:
  //  JsonReply post(const JsonRequest& msg);
public:

};

#endif // HTTPHANDLER_H
