#include "PlaceOrderController.h"
#include <QMessageBox>
#include <QTableWidget>
#include <QSpinBox>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

PlaceOrderController::PlaceOrderController(QObject *parent) : QObject(parent),
    m_placeOrderWindow(new PlaceOrderWindow), m_placeOrderHandler(new HttpHandler)
{
    connect(m_placeOrderWindow, &PlaceOrderWindow::resetCart, this, &PlaceOrderController::resetCart);
    connect(m_placeOrderWindow, &PlaceOrderWindow::placeOrderButtonClicked, this, &PlaceOrderController::placeOrder);
    connect(m_placeOrderWindow, &PlaceOrderWindow::cartCellChanged, this, &PlaceOrderController::cartCellChanged);
    connect(m_placeOrderHandler, &HttpHandler::finished, this, &PlaceOrderController::resetCart);
    connect(m_placeOrderHandler, &HttpHandler::finished, view(), &PlaceOrderWindow::accept);
    connect(m_placeOrderHandler, &HttpHandler::replyErrors, this, &PlaceOrderController::orderPlacementFailed);
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
        QUrl placeOrderUrl(HttpHandler::ORDER_PLACEMENT_URL_STRING);
        m_placeOrderHandler->setUrl(placeOrderUrl);
        m_placeOrderHandler->request()->setRawHeader("Content-Type", "application/json");
        m_placeOrderHandler->setUser(view()->order()->user()->properties().name());
        m_placeOrderHandler->setPassword(view()->order()->user()->properties().password());
        QByteArray orderstr = m_placeOrderWindow->order()->asJson().toJson(QJsonDocument::Compact);
        m_placeOrderHandler->sendRequest(orderstr);
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

void PlaceOrderController::orderPlacementFailed(const int &code)
{
    QMessageBox::warning(0, "Error placing order", m_placeOrderHandler->reply()->errorString());
    Q_UNUSED(code)
}
