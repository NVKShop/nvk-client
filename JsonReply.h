#ifndef JSONREPLY_H
#define JSONREPLY_H

#include <QObject>
#include "JsonQuery.h"
#include "Product.h"
#include "User.h"

class JsonReply : public JsonQuery
{
    Q_OBJECT
public:
    explicit JsonReply(const QJsonDocument& doc);

    QVector<Product *> getProducts() const;
    User *getUser() const;
signals:

public slots:

};

#endif // JSONREPLY_H
