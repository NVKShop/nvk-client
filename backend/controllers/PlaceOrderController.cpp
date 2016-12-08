#include "PlaceOrderController.h"

PlaceOrderController::PlaceOrderController(QObject *parent) : QObject(parent),
    m_placeOrderWindow(new PlaceOrderWindow)
{
    connect(m_placeOrderWindow, &PlaceOrderWindow::resetCart, this, &PlaceOrderController::resetCart);
    connect(m_placeOrderWindow, &PlaceOrderWindow::placeOrderButtonClicked, this, &PlaceOrderController::placeOrder);
}

PlaceOrderWindow* PlaceOrderController::view() const
{
    return m_placeOrderWindow;
}

void PlaceOrderController::setOrder(Order *order)
{
    m_placeOrderWindow->setOrder(order);
}

PlaceOrderController::~PlaceOrderController()
{
    delete m_placeOrderWindow;
}

void PlaceOrderController::placeOrder()
{

    // stuff here + check connection

    //if successful
    m_placeOrderWindow->order()->user()->cart()->resetCart();

    m_placeOrderWindow->accept();
}

void PlaceOrderController::resetCart()
{
    m_placeOrderWindow->order()->user()->cart()->resetCart();
    setOrder(m_placeOrderWindow->order());
}
