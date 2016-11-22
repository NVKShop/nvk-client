#ifndef HTTPHANDLER_H
#define HTTPHANDLER_H
#include "NetworkHandler.h"
#include "JsonReply.h"
#include "JsonRequest.h"

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
    QJsonDocument post(const QString& msg);
};

#endif // HTTPHANDLER_H
