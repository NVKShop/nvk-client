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
public Q_SLOTS:
  //  JsonReply post(const JsonRequest& msg);
};

#endif // HTTPHANDLER_H
