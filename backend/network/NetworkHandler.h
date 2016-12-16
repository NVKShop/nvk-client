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

    static bool isOnline();
    bool isConnectedToTheInternet();
    QNetworkReply *reply() const;
    void sendRequest(const QString &data);

private:
    QNetworkAccessManager* m_NetworkAccessManager;

Q_SIGNALS:
    void readyRead(const QString& data);
    void replyErrors(const int&);
protected:
    QNetworkRequest* m_HttpRequest;
    QNetworkReply* m_HttpReply;

private Q_SLOTS:
    void replyReadyRead();
    void replyFinished();
    void replyError(QNetworkReply::NetworkError);
#ifndef QT_NO_SSL
    void sslError(const QList<QSslError> &errors);
#endif
};

#endif // NETWORKHANDLER_H
