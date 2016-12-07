#ifndef PLACEORDERCONTROLLER_H
#define PLACEORDERCONTROLLER_H

#include "frontend/widgets/PlaceOrderWindow.h"
#include "backend/Order.h"
#include <QObject>

class PlaceOrderController : public QObject
{
    Q_OBJECT
public:
    explicit PlaceOrderController(QObject *parent = 0);
    PlaceOrderWindow* view() const;
    ~PlaceOrderController();
    void setOrder(Order* order);
Q_SIGNALS:

public Q_SLOTS:
    void placeOrder();
private:
    PlaceOrderWindow* m_placeOrderWindow;
};

#endif // PLACEORDERCONTROLLER_H
