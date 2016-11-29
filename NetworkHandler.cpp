#include "NetworkHandler.h"
#include <QByteArray>
#include <QDebug>
#include <QNetworkInterface>
#include <QList>
#include <QEventLoop>

NetworkHandler::NetworkHandler(QObject *parent) : QObject(parent),
    m_HttpReply(Q_NULLPTR)
{
    m_NetworkAccessManager = new QNetworkAccessManager(this);
}

void NetworkHandler::sendRequest(const QString& data)
{
    m_HttpReply = m_NetworkAccessManager->post(*m_HttpRequest,
                                               QByteArray::fromRawData(data.toStdString().c_str(), data.size()));
    connect(m_HttpReply, &QNetworkReply::finished, this, &NetworkHandler::replyFinished);
    connect(m_HttpReply,
            static_cast<void(QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),
            this, &NetworkHandler::replyError);
    connect(m_HttpReply, &QNetworkReply::readyRead, this, &NetworkHandler::replyReadyRead);
#ifndef QT_NO_SSL
    connect(m_HttpReply, &QNetworkReply::sslErrors, this, &NetworkHandler::sslError);
#endif
}

bool NetworkHandler::isOnline()
{
    QList<QNetworkInterface> networkInterfaces = QNetworkInterface::allInterfaces();
    foreach (QNetworkInterface interface, networkInterfaces) {
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
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    if(reply->bytesAvailable()) {
        return true;
    }
    else {
        return false;
    }
}

QNetworkReply *NetworkHandler::reply() const
{
    return m_HttpReply;
}

NetworkHandler::~NetworkHandler()
{
    delete m_HttpReply;
    delete m_HttpRequest;
    delete m_NetworkAccessManager;
}

void NetworkHandler::replyReadyRead()
{
    qDebug() << "Ready to read!";
    emit readyRead(m_HttpReply->header(QNetworkRequest::ServerHeader).toString());
    qDebug() << m_HttpReply->header(QNetworkRequest::ServerHeader).toString();
}

void NetworkHandler::replyFinished()
{
    qDebug() << "Finished!";
}

void NetworkHandler::replyError(QNetworkReply::NetworkError err)
{
    Q_UNUSED(err)
    qDebug() << m_HttpReply->errorString();
}

#ifndef QT_NO_SSL
void NetworkHandler::sslError(const QList<QSslError> &errors)
{
    foreach (const QSslError& err, errors) {
        qDebug() << err.errorString();
    }
}
#endif
