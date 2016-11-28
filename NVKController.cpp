#include "NVKController.h"

NVKController::NVKController(QObject *parent) : QObject(parent)
{

}

void NVKController::setActiveWindow(QWidget *window)
{
    m_activeWindow->hide();
    m_activeWindow = window;
    m_activeWindow->show();
}

