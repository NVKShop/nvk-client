#include "ManageOrderController.h"

ManageOrderController::ManageOrderController(QObject *parent) : QObject(parent),
    m_manageOrderWindow(new ManageOrderWindow)
{

}

ManageOrderWindow* ManageOrderController::view() const
{
    return m_manageOrderWindow;
}

ManageOrderController::~ManageOrderController()
{
    delete m_manageOrderWindow;
}
