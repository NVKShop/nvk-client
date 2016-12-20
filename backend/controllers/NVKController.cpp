#include "backend/controllers/NVKController.h"
NVKController::NVKController(QObject *parent) : QObject(parent), m_mainWindow(new NVKMainWindow),
    m_loginController(new LoginController),
    m_forgotUserDataController(new ForgotUserDataController),
    m_manageOrderController(new ManageOrderController),
    m_placeOrderController(new PlaceOrderController),
    m_productPreviewController(new ProductPreviewController),
    m_productSearchController(new ProductSearchController),
    m_userSettingsController(new UserSettingsController),
    m_mainWindowHandler(new HttpHandler),
    m_detailedProductHandler(new HttpHandler)
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
    connect(m_mainWindow, &NVKMainWindow::nextPage, this, &NVKController::nextPage);
    connect(m_mainWindow, &NVKMainWindow::previousPage, this, &NVKController::previousPage);
    connect(m_mainWindow, &NVKMainWindow::pageSizeChanged, this, &NVKController::pageSizeChanged);

    connect(m_productPreviewController, &ProductPreviewController::addToCart, this, &NVKController::addToCart);
    connect(m_mainWindow, &NVKMainWindow::shown, this, &NVKController::connectToScenes);

    connect(m_productSearchController, &ProductSearchController::searchProduct, this, &NVKController::searchProducts);
    connect(this, &NVKController::searched, m_productSearchController, &ProductSearchController::searched);

    connect(m_mainWindowHandler, &HttpHandler::finished, this, &NVKController::loadCategories);
    connect(m_detailedProductHandler, &HttpHandler::finished, this, &NVKController::showDetailedProductPreview);
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
    const long pid = product->properties().id();
    m_detailedProductHandler->setUrl(QUrl(HttpHandler::DETAILED_PRODUCT_URL_STRING.arg(pid)));
    m_detailedProductHandler->sendRequest(QByteArray());

    m_productPreviewController->setProduct(product);
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
    m_mainWindow->order()->user()->cart()->addProduct(product);
}

void NVKController::connectToScenes()
{
    connect(m_mainWindow->productsScene(), &ProductsScene::productDoubleClicked, m_mainWindow, &NVKMainWindow::productDoubleClicked);
    connect(m_mainWindow->categoriesScene(), &CategoriesScene::selectionChangedNew, this, &NVKController::categoryChanged);

    connect(m_productPreviewController, &ProductPreviewController::addedToCart, m_mainWindow->userPanelScene(), &UserPanelScene::itemAdded);
    connect(m_placeOrderController, &PlaceOrderController::setQuantityText, m_mainWindow->userPanelScene(), &UserPanelScene::setQuantity);
    connect(m_mainWindow->productsScene(), &ProductsScene::scrollToTop, m_mainWindow->productsView(), &ProductsView::scrollToTop);

    m_mainWindowHandler->setUrl(QUrl(HttpHandler::LIST_CATEGORIES_URL_STRING));
    m_mainWindowHandler->sendRequest(QByteArray());

    disconnect(m_mainWindow, &NVKMainWindow::shown, this, &NVKController::connectToScenes);
}

void NVKController::categoryChanged(Category *newCategory)
{
    if (view()->categoriesView()->currentCategory() != newCategory) {
        view()->categoriesView()->setCurrentCategory(newCategory);
        view()->productsView()->scrollToTop();

        QUrl productsByCatUrl = HttpHandler::PRODUCTS_BY_CATEGORY_URL_STRING.arg(QString::number(newCategory->properties().id())).
                arg(QString::number(view()->pageSizeCb()->currentText().toInt()))
                .arg(QString::number(view()->currentPage()));
        m_mainWindowHandler->setUrl(productsByCatUrl);
        m_mainWindowHandler->sendRequest(QByteArray());
    }
}

void NVKController::searchProducts(ProductSearch *psearch)
{
    CategoryProperty categoryName(-1,psearch->searchTerm(), -1);
    CategoriesScene* scene = m_mainWindow->categoriesScene();

    Category* searchResultCategory = new Category(QPixmap(":/images/catBg.png"), categoryName, m_mainWindow->categoriesView()->width());

    //if search ok..emit seached()

    if (m_productSearchController->searchedAlready())
    {
        scene->removeLast();
    }
    if (!m_productSearchController->searchedAlready())
    {
        emit searched();
    }

    disconnect(this, &NVKController::searched, m_productSearchController, &ProductSearchController::searched);
    scene->addCategory(searchResultCategory);

    // do the stuff..add new category etc
}

void NVKController::nextPage()
{
    view()->setCurrentPage(view()->currentPage()+1);

    QUrl productsByCatUrl = HttpHandler::PRODUCTS_BY_CATEGORY_URL_STRING.arg(QString::number(view()->categoriesView()->currentCategory()->properties().id())).
            arg(QString::number(view()->pageSizeCb()->currentText().toInt()))
            .arg(QString::number(view()->currentPage()));
    m_mainWindowHandler->setUrl(productsByCatUrl);
    m_mainWindowHandler->sendRequest(QByteArray());

    view()->currentPageLabel()->setText(QString::number(view()->currentPage()));
}

void NVKController::previousPage()
{
    view()->setCurrentPage(view()->currentPage()-1);
    QUrl productsByCatUrl = HttpHandler::PRODUCTS_BY_CATEGORY_URL_STRING.arg(QString::number(view()->categoriesView()->currentCategory()->properties().id())).
            arg(QString::number(view()->pageSizeCb()->currentText().toInt()))
            .arg(QString::number(view()->currentPage()));
    m_mainWindowHandler->setUrl(productsByCatUrl);
    m_mainWindowHandler->sendRequest(QByteArray());
    view()->currentPageLabel()->setText(QString::number(view()->currentPage()));
}

void NVKController::pageSizeChanged(int idx)
{
    const int val = view()->pageSizeCb()->itemText(idx).toInt();
    QUrl productsByCatUrl = HttpHandler::PRODUCTS_BY_CATEGORY_URL_STRING.arg(QString::number(view()->categoriesView()->currentCategory()->properties().id())).
            arg(QString::number(val))
            .arg(QString::number(view()->currentPage()));
    m_mainWindowHandler->setUrl(productsByCatUrl);
    m_mainWindowHandler->sendRequest(QByteArray());
}

void NVKController::loadProductsInCategory()
{
    JsonReply productsRequestReply(QJsonDocument::fromJson(m_mainWindowHandler->reply()->readAll()));
    ProductsScene* scene = static_cast<ProductsScene*>(view()->productsScene());
    QVector<Product*> prods = productsRequestReply.products();
    view()->previousPageButton()->setEnabled(productsRequestReply.previousPageExists());
    view()->nextPageButton()->setEnabled(productsRequestReply.nextPageExists());
    scene->setItems(prods);

    foreach (Product* p, view()->order()->user()->cart()->products())
    {
        foreach (Product* pr, prods) {
            if (p->properties().id() == pr->properties().id())
            {
                pr->addedToCart();
            }
        }
    }

    view()->productsInCategoryLabel()->setText(QString::number(productsRequestReply.products().size()) + QLatin1String(" products in this category"));
    view()->productsInCategoryLabel()->adjustSize();
}

void NVKController::loadCategories()
{
    QString r = QString::fromUtf8(m_mainWindowHandler->reply()->readAll());
    JsonReply reply(QJsonDocument::fromJson(r.toUtf8()));

    QVector<Category*> cats = reply.categories(m_mainWindow->categoriesView()->width());
    view()->categoriesScene()->setItems(cats);

    disconnect(m_mainWindowHandler, &HttpHandler::finished, this, &NVKController::loadCategories);
    connect(m_mainWindowHandler, &HttpHandler::finished, this, &NVKController::loadProductsInCategory);
}

void NVKController::showDetailedProductPreview()
{
    JsonReply detailedProductReply(QJsonDocument::fromJson(m_detailedProductHandler->reply()->readAll()));
    if (m_productPreviewController->product()->originalPixmap().isNull())
    {
        QPixmap img = detailedProductReply.productPreviewPicture();
        m_productPreviewController->setPixmap(img);
    }
    else
    {
        m_productPreviewController->setPixmap(m_productPreviewController->product()->originalPixmap());
    }

    popUpWindow(m_productPreviewController->view());
}
