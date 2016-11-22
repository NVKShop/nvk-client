#ifndef NVKCONTROLLER_H
#define NVKCONTROLLER_H

#include <QObject>
#include "HttpHandler.h"

class NVKController : public QObject
{
    Q_OBJECT
public:
    explicit NVKController(QObject *parent = 0);

signals:

public slots:

private:
    HttpHandler m_HttpHandler;

    User m_user;

};

#endif // NVKCONTROLLER_H
