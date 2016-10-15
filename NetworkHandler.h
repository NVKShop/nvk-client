#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QSslError>
#include <QSsl>

class NetworkHandler : public QObject
{
    Q_OBJECT
public:
    explicit NetworkHandler(QObject *parent = 0);
    ~NetworkHandler();
private:
    QNetworkAccessManager* m_NetworkAccessManager;
    QNetworkReply* m_HttpReply;
    QNetworkRequest* m_HttpRequest;

Q_SIGNALS:
    void readyRead(const QString& data);
public Q_SLOTS:
    void sendRequest();

private Q_SLOTS:
    void replyReadyRead();
    void replyFinished();
    void replyError(QNetworkReply::NetworkError);
#ifndef QT_NO_SSL
    void sslError(const QList<QSslError> &errors);
#endif
};

#endif // NETWORKHANDLER_H
