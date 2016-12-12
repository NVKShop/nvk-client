#ifndef JSONQUERY_H
#define JSONQUERY_H

#include <QObject>
#include <QJsonDocument>

class JsonQuery : public QObject
{
    Q_OBJECT
public:
    explicit JsonQuery(QObject *parent = 0);
    QJsonDocument document() const;
signals:

public slots:

protected:
    QJsonDocument m_document;
};

#endif // JSONQUERY_H
