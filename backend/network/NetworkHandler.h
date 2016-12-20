#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QSslError>
#include <QSsl>
#include <QAuthenticator>

class NetworkHandler : public QObject
{
    Q_OBJECT
public:
    explicit NetworkHandler(QObject *parent = 0);
    ~NetworkHandler();

    static bool isOnline();
    bool isConnectedToTheInternet();
    QNetworkReply *reply() const;
    QNetworkRequest* request() const;
    void sendRequest(const QByteArray &data);

    void setUser(const QString& user);
    void setPassword(const QString& pw);
protected:
    QNetworkReply* m_HttpReply;
    QNetworkRequest* m_HttpRequest;
private:
    QNetworkAccessManager* m_NetworkAccessManager;
    QAuthenticator* m_authenticator;
    bool m_finished = false;
Q_SIGNALS:
    void readyRead(const QString& data);
    void replyErrors(const int&);
    void finished();

private Q_SLOTS:
    void replyFinished();
    void auth(QNetworkReply* reply, QAuthenticator* auth);
#ifndef QT_NO_SSL
    void sslError(const QList<QSslError> &errors);
#endif
};

#endif // NETWORKHANDLER_H
