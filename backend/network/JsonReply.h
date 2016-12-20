#ifndef JSONREPLY_H
#define JSONREPLY_H

#include <QObject>
#include "backend/network/JsonQuery.h"
#include "backend/graphics_items/Product.h"
#include "backend/User.h"
#include "backend/graphics_items/Category.h"

class JsonReply : public JsonQuery
{
    Q_OBJECT
public:
    explicit JsonReply(const QJsonDocument& doc);

    QVector<Product *> products() const;
    QVector<Category*> categories(const int& width) const;
    QPixmap productPreviewPicture() const;
    QString productDescription() const;
    bool previousPageExists() const;
    bool nextPageExists() const;
    User *user() const;
Q_SIGNALS:

public Q_SLOTS:

private:

};

#endif // JSONREPLY_H
