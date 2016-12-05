#include "PlaceOrderController.h"

PlaceOrderController::PlaceOrderController(QObject *parent) : QObject(parent),
    m_placeOrderWindow(new PlaceOrderWindow)
{
}

PlaceOrderWindow* PlaceOrderController::view() const
{
    return m_placeOrderWindow;
}

void PlaceOrderController::setOrder(Order *order)
{
    m_placeOrderWindow->setOrder(order);
}
