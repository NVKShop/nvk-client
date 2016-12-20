#include "backend/network/NetworkHandler.h"
#include <QByteArray>
#include <QDebug>
#include <QNetworkInterface>
#include <QList>
#include <QEventLoop>
#include <QTimer>

NetworkHandler::NetworkHandler(QObject *parent) : QObject(parent),
    m_HttpReply(Q_NULLPTR), m_HttpRequest(Q_NULLPTR), m_authenticator(new QAuthenticator)
{
    m_NetworkAccessManager = new QNetworkAccessManager(this);
    connect(m_NetworkAccessManager, &QNetworkAccessManager::authenticationRequired, this, &NetworkHandler::auth);
}

void NetworkHandler::setUser(const QString &user)
{
    m_authenticator->setUser(user);
}

void NetworkHandler::setPassword(const QString &pw)
{
    m_authenticator->setPassword(pw);
}

void NetworkHandler::sendRequest(const QByteArray& data)
{
    m_finished = false;

    if (data.isNull())
    {
        m_HttpReply = m_NetworkAccessManager->get(*m_HttpRequest);
    }
    else
    {
        m_HttpReply = m_NetworkAccessManager->post(*m_HttpRequest, data);
    }

    connect(m_HttpReply, &QNetworkReply::finished, this, &NetworkHandler::replyFinished);

#ifndef QT_NO_SSL
    connect(m_HttpReply, &QNetworkReply::sslErrors, this, &NetworkHandler::sslError);
#endif
}

bool NetworkHandler::isOnline()
{
    const QList<QNetworkInterface>& networkInterfaces = QNetworkInterface::allInterfaces();
    foreach (const QNetworkInterface& interface, networkInterfaces) {
        if (interface.flags().testFlag(QNetworkInterface::IsUp) &&
                !interface.flags().testFlag(QNetworkInterface::IsLoopBack)) {
            return true;
        }
    }

    return false;
}

bool NetworkHandler::isConnectedToTheInternet()
{
    QNetworkAccessManager nam;
    QNetworkRequest req(QUrl("http://www.google.com"));
    QNetworkReply *reply = nam.get(req);
    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);

    connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    timer.start(2500);
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    if (timer.isActive())
    {
        if(reply->bytesAvailable()) {
            timer.stop();
            delete reply;
            return true;
        }
        else
        {
            delete reply;
            return false;
        }
    }
    else
    {
        reply->abort();
        delete reply;
        return false;
    }
}

QNetworkReply *NetworkHandler::reply() const
{
    return m_HttpReply;
}

QNetworkRequest* NetworkHandler::request() const
{
    return m_HttpRequest;
}

NetworkHandler::~NetworkHandler()
{
    delete m_HttpReply;
    delete m_HttpRequest;
    delete m_NetworkAccessManager;
}

void NetworkHandler::replyFinished()
{
    if (m_HttpReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() == 200)
    {
        emit finished();
        emit readyRead(QString(m_HttpReply->readAll()));
    }
    else
    {
        emit replyErrors(m_HttpReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt());
        qDebug() << m_HttpReply->errorString();
    }
}

#ifndef QT_NO_SSL
void NetworkHandler::sslError(const QList<QSslError> &errors)
{
    foreach (const QSslError& err, errors) {
        qDebug() << err.errorString();
    }
}
#endif

void NetworkHandler::auth(QNetworkReply *reply, QAuthenticator *auth)
{
    Q_UNUSED(reply)
    qDebug() << "auth: " << auth->realm();
    auth->setUser(m_authenticator->user());
    auth->setPassword(m_authenticator->password());
    qDebug() << m_authenticator->user() << " " << m_authenticator->password();
}
