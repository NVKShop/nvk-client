#ifndef PLACEORDERCONTROLLER_H
#define PLACEORDERCONTROLLER_H

#include "frontend/widgets/PlaceOrderWindow.h"
#include "backend/network/HttpHandler.h"
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
    void setQuantityText(const int val);
public Q_SLOTS:
    void placeOrder();
    void resetCart();
private Q_SLOTS:
    void cartCellChanged(int row, int val);
    void orderPlacementFailed(const int& code);
private:
    PlaceOrderWindow* m_placeOrderWindow;
    HttpHandler* m_placeOrderHandler;
};

#endif // PLACEORDERCONTROLLER_H
