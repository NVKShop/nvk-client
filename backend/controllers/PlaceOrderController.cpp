#include "PlaceOrderController.h"
#include <QMessageBox>
#include <QTableWidget>
#include <QSpinBox>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

PlaceOrderController::PlaceOrderController(QObject *parent) : QObject(parent),
    m_placeOrderWindow(new PlaceOrderWindow)
{
    connect(m_placeOrderWindow, &PlaceOrderWindow::resetCart, this, &PlaceOrderController::resetCart);
    connect(m_placeOrderWindow, &PlaceOrderWindow::placeOrderButtonClicked, this, &PlaceOrderController::placeOrder);
    connect(m_placeOrderWindow, &PlaceOrderWindow::cartCellChanged, this, &PlaceOrderController::cartCellChanged);
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
    if (view()->order()->user()->cart()->products().size() == 0 )
    {
        QMessageBox::warning(0, "Error placing order", "Can't place an empty order!");
    }
    else
    {
        // stuff here + check connection

        // NEW
        /*QUrl placeOrderUrl(HttpHandler::ORDER_PLACEMENT_URL_STRING);
        HttpHandler placeOrderHandler(placeOrderUrl);

        QString orderstr = m_placeOrderWindow->order()->asJson().toJson(QJsonDocument::Compact);
        placeOrderHandler.sendRequest(orderstr);*/

        m_placeOrderWindow->order()->user()->cart()->resetCart();
        emit setQuantityText(0);
        m_placeOrderWindow->accept();
    }
}

void PlaceOrderController::resetCart()
{
    m_placeOrderWindow->order()->user()->cart()->resetCart();
    setOrder(m_placeOrderWindow->order());
    emit setQuantityText(0);
}

void PlaceOrderController::cartCellChanged(int row, int val)
{
    m_placeOrderWindow->order()->user()->cart()->products()[row]->setQuantity(val);
    setOrder(m_placeOrderWindow->order());
    emit setQuantityText(m_placeOrderWindow->order()->productsCount());
}

