#ifndef NVKCONTROLLER_H
#define NVKCONTROLLER_H

#include <QObject>
#include "backend/network/HttpHandler.h"
#include "frontend/widgets/ForgotUserDataWindow.h"
#include "frontend/widgets/LoginWindow.h"
#include "frontend/widgets/NVKMainWindow.h"
#include "frontend/widgets/PlaceOrderWindow.h"

class NVKController : public QObject
{
    Q_OBJECT
public:
    explicit NVKController(QObject *parent = 0);

signals:

public Q_SLOTS:

private Q_SLOTS:
    void changeActiveWindow(QWidget* window);
    void loginUser();
    void placeOrder(Order* order);
    void forgotUserData(const QString& email);
    void loginCancelled();
    void mainClosing();
private:

    HttpHandler m_HttpHandler;
    User* m_user;

    LoginWindow* m_loginWindow;
    ForgotUserDataWindow* m_forgotUserDataWindow;
    NVKMainWindow* m_mainWindow;
    PlaceOrderWindow* m_placeOrderWindow;

    QWidget* m_activeWindow;
};

#endif // NVKCONTROLLER_H
