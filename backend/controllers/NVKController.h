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
#include "backend/ProductSearch.h"

#include "frontend/widgets/NVKMainWindow.h"

class NVKController : public QObject
{
    Q_OBJECT
public:
    explicit NVKController(QObject *parent = 0);
    NVKMainWindow* view() const;
    void loginWindow();
public Q_SLOTS:

private Q_SLOTS:
    void changeActiveWindow(QWidget* window);
    void popUpWindow(QWidget* window);
    void placeOrder(Order* order);
    void loginCancelled();
    void mainClosing();
    void showForgotUserWindow();
    void userLogged(User *user);
    void forgotUserWindowRejected();
    void showProductSearchWindow();
    void showProductPreview(Product* product);
    void successfulReminderSent();
    void showCartWindow();
    void showSettingsWindow();
    void addToCart(Product* product);
    void connectToScenes();
    void searchProducts(ProductSearch* psearch);
    void nextPage();
    void previousPage();
    void pageSizeChanged(int idx);
    void loadCategories();
    void loadProductsInCategory();
    void categoryChanged(Category *newCategory);
    void showDetailedProductPreview();
    void searchFinished();
Q_SIGNALS:
    void searched();
private:

    NVKMainWindow* m_mainWindow;

    HttpHandler* m_mainWindowHandler;
    HttpHandler* m_detailedProductHandler;
    HttpHandler* m_searchHandler;

    LoginController* m_loginController;
    ForgotUserDataController* m_forgotUserDataController;
    ManageOrderController* m_manageOrderController;
    PlaceOrderController* m_placeOrderController;
    ProductPreviewController* m_productPreviewController;
    ProductSearchController* m_productSearchController;
    UserSettingsController* m_userSettingsController;

    QWidget* m_activeWindow;

};

#endif // NVKCONTROLLER_H
