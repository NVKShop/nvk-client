#ifndef PLACEORDERCONTROLLER_H
#define PLACEORDERCONTROLLER_H

#include <QObject>

class PlaceOrderController : public QObject
{
    Q_OBJECT
public:
    explicit PlaceOrderController(QObject *parent = 0);

signals:

public slots:
};

#endif // PLACEORDERCONTROLLER_H