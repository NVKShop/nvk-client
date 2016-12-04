#ifndef JSONREQUEST_H
#define JSONREQUEST_H

#include <QObject>
#include "backend/network/JsonQuery.h"
#include "backend/User.h"

class JsonRequest : public JsonQuery
{
    Q_OBJECT
public:
    explicit JsonRequest(const User& user, const QString& category = "", const int from = 0, const int to = 0);

signals:

public slots:
};

#endif // JSONREQUEST_H
