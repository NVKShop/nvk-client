#ifndef NVKCONTROLLER_H
#define NVKCONTROLLER_H

#include <QObject>
#include "backend/network/HttpHandler.h"
#include "backend/controllers/ForgotUserDataController.h"
#include "backend/controllers/LoginController.h"
#include "backend/controllers/ManageOrderController.h"
#include "backend/controllers/PlaceOrderController.h"
#include "backend/controllers/ProductPreviewController.h"
#include "backend/controllers/ProductSearchController.h"
#include "backend/controllers/UserSettingsController.h"

#include "frontend/widgets/NVKMainWindow.h"

class NVKController : public QObject
{
    Q_OBJECT
public:
    explicit NVKController(QObject *parent = 0);
    NVKMainWindow* view() const;
    void loginWindow();
Q_SIGNALS:

public Q_SLOTS:

private Q_SLOTS:
    void changeActiveWindow(QWidget* window);
    void placeOrder(Order* order);
    void loginCancelled();
    void mainClosing();
    void showForgotUserWindow();
    void userLogged(User *user);
    void forgotUserWindowRejected();
private:

    HttpHandler m_HttpHandler;
    User* m_user;

    LoginController* m_loginController;
    ForgotUserDataController* m_forgotUserDataController;
    ManageOrderController* m_manageOrderController;
    PlaceOrderController* m_placeOrderController;
    ProductPreviewController* m_productPreviewController;
    ProductSearchController* m_productSearchController;
    UserSettingsController* m_userSettingsController;

    NVKMainWindow* m_mainWindow;

    QWidget* m_activeWindow;
};

#endif // NVKCONTROLLER_H