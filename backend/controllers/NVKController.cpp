#include "backend/controllers/NVKController.h"

NVKController::NVKController(QObject *parent) : QObject(parent), m_mainWindow(new NVKMainWindow),
    m_loginController(new LoginController),
    m_forgotUserDataController(new ForgotUserDataController),
    m_manageOrderController(new ManageOrderController),
    m_placeOrderController(new PlaceOrderController),
    m_productPreviewController(new ProductPreviewController),
    m_productSearchController(new ProductSearchController),
    m_userSettingsController(new UserSettingsController)
{

    connect(m_loginController->view(), &LoginWindow::showForgotUserWindow, this, &NVKController::showForgotUserWindow);
    connect(m_loginController->view(), &LoginWindow::rejected, this, &NVKController::loginCancelled);

    connect(m_loginController, &LoginController::loginOk, this, &NVKController::userLogged);

    connect(m_mainWindow, &NVKMainWindow::closing, this, &NVKController::mainClosing);

    connect(m_forgotUserDataController->view(), &ForgotUserDataWindow::rejected, this, &NVKController::forgotUserWindowRejected);
    connect(m_forgotUserDataController, &ForgotUserDataController::successfulReminder, this, &NVKController::successfulReminderSent);

    connect(m_mainWindow, &NVKMainWindow::searchProductClicked, this, &NVKController::showProductSearchWindow);
    connect(m_mainWindow, &NVKMainWindow::productDoubleClicked, this, &NVKController::showProductPreview);
    connect(m_mainWindow, &NVKMainWindow::showCart, this, &NVKController::showCartWindow);
    connect(m_mainWindow, &NVKMainWindow::showSettings, this, &NVKController::showSettingsWindow);

    connect(m_productPreviewController, &ProductPreviewController::addToCart, this, &NVKController::addToCart);

}

void NVKController::changeActiveWindow(QWidget *window)
{
    window->show();

    if (m_activeWindow != nullptr) {
        m_activeWindow->hide();
    }
    m_activeWindow = window;
}

void NVKController::placeOrder(Order *order)
{
    m_placeOrderController->setOrder(order);
    changeActiveWindow(m_placeOrderController->view());
}

void NVKController::popUpWindow(QWidget *window)
{
    if (window->isHidden())
    {
        window->show();
    }
    else
    {
#ifndef Q_OS_ANDROID
        if (!window->hasFocus())
        {
            window->raise();
        }
#endif
    }
}

void NVKController::loginCancelled()
{
    mainClosing();
}

void NVKController::mainClosing()
{
    delete m_loginController;
    delete m_forgotUserDataController;
    delete m_manageOrderController;
    delete m_productPreviewController;
    delete m_productSearchController;
    delete m_userSettingsController;
    delete m_placeOrderController;
}

void NVKController::showForgotUserWindow()
{
    changeActiveWindow(m_forgotUserDataController->view());
}

void NVKController::userLogged(User* user)
{
    m_mainWindow->order()->setUser(user);
    changeActiveWindow(view());
}

NVKMainWindow* NVKController::view() const
{
    return m_mainWindow;
}

void NVKController::forgotUserWindowRejected()
{
    changeActiveWindow(m_loginController->view());
}

void NVKController::loginWindow()
{
    m_loginController->view()->show();;
    m_activeWindow = m_loginController->view();
}

void NVKController::showProductSearchWindow()
{
    QStringList categories;

    foreach (Category* cat, view()->categories()) {
        categories << cat->name();
    }

    m_productSearchController->setCategories(categories);
    popUpWindow(m_productSearchController->view());
}

void NVKController::showProductPreview(Product *product)
{
    m_productPreviewController->setProduct(product);
    qDebug() << "prodView" << product->properties().name();
    popUpWindow(m_productPreviewController->view());
}

void NVKController::successfulReminderSent()
{
    changeActiveWindow(m_loginController->view());
}

void NVKController::showCartWindow()
{
    m_placeOrderController->setOrder(m_mainWindow->order());
    popUpWindow(m_placeOrderController->view());
}

void NVKController::showSettingsWindow()
{
    m_userSettingsController->setUser(m_mainWindow->order()->user());
    popUpWindow(m_userSettingsController->view());
}

void NVKController::addToCart(Product *product)
{
    qDebug() << "nvkC " << product->properties().name();
    m_mainWindow->order()->user()->cart()->addProduct(product);
}

