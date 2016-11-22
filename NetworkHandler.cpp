#include "NetworkHandler.h"
#include <QByteArray>
#include <QDebug>

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
