#include "frontend/widgets/NVKMainWindow.h"

#include "ui_nvkmainwindow.h"
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QScrollBar>
#include <QComboBox>
#include <QDebug>

NVKMainWindow::NVKMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NVKMainWindow), m_order(new Order())
{
    setWindowTitle("NVK Shop");
    ui->setupUi(this);

#ifdef Q_OS_ANDROID
    //Set sizes for Android
    QString barstyle =  "QScrollBar:horizontal {height: 7px;}" "QScrollBar:vertical {width: 9px;}";
    ui->productsView->verticalScrollBar()->setStyleSheet(barstyle);
    ui->categoriesView->verticalScrollBar()->setStyleSheet(barstyle);

#else
    QDesktopWidget* dw = QApplication::desktop();
    dw->availableGeometry(dw->primaryScreen());
    resize( dw->availableGeometry(dw->primaryScreen()).size());
#endif
    qDebug() << ui->productsView->width();
    setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->searchButton, &QPushButton::clicked, this, &NVKMainWindow::searchProductClicked);
    connect(ui->nextPageButton, &QPushButton::clicked, this, &NVKMainWindow::nextPage);
    connect(ui->previousPageButton, &QPushButton::clicked, this, &NVKMainWindow::previousPage);

    connect(ui->pageSizeComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &NVKMainWindow::pageSizeChanged);
    QPalette p(palette());
    setAutoFillBackground(true);
    p.setColor(QPalette::Background, QColor::fromRgb(0x42, 0x41, 0x3D));
    setPalette(p);

    QPalette pt(ui->productsInCategoryLabel->palette());
    pt.setColor(QPalette::WindowText, QColor::fromRgb(0xFF, 0xCE,0x2B));
    ui->productsInCategoryLabel->setPalette(pt);
    ui->pageSizeLabel->setPalette(pt);

    ui->searchButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                      "stop: 0 white, stop: 1 grey);"
                                                      "border-style: solid;"
                                                      "border-width: 2px;"
                                                      "border-color: black;"
                                                      "border-radius: 15px;}"));

    ui->previousPageButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                            "stop: 0 white, stop: 1 grey);"
                                                            "border-style: solid;"
                                                            "border-width: 2px;"
                                                            "border-color: black;"
                                                            "border-radius: 15px;}"));

    ui->nextPageButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                        "stop: 0 white, stop: 1 grey);"
                                                        "border-style: solid;"
                                                        "border-width: 2px;"
                                                        "border-color: black;"
                                                        "border-radius: 15px;}"));
    ui->previousPageButton->setDisabled(true);
}

void NVKMainWindow::setupViews()
{
    m_productsView = ui->productsView;
    m_productsView->show();
    ProductsScene* pScene = new ProductsScene(m_productsView->width());
    m_productsView->setScene(pScene);
    // NEW
    // categorychanged..
    //pScene->setItems(m_categoryMapped.values(m_categoryMapped.firstKey()));

    m_categoriesView = ui->categoriesView;

    CategoriesScene* cScene = new CategoriesScene();
    //cScene->setItems(categories);
    m_categoriesView->setScene(cScene);
    //m_categoriesView->setCurrentCategory(cats.at(0));

    m_userPanelView = ui->userPanelView;
    UserPanelScene* uScene = new UserPanelScene();

    connect(uScene, &UserPanelScene::cartClicked, this, &NVKMainWindow::showCart);
    connect(uScene, &UserPanelScene::settingsClicked, this, &NVKMainWindow::showSettings);

    uScene->setSceneRect(0,0, m_userPanelView->width(), m_userPanelView->height());
    uScene->setupScene();
    uScene->setUserName(m_order->user()->properties().name());

    m_userPanelView->setScene(uScene);
}

QVector<Category*> NVKMainWindow::categories() const
{
    return qobject_cast<CategoriesScene*>(m_categoriesView->scene())->categories();
}


NVKMainWindow::~NVKMainWindow()
{
    delete ui;
    delete m_categoriesView;
    delete m_order;
    delete m_productsView;
    delete m_userPanelView;
}

void NVKMainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() & Qt::Key_Escape)
    {
        close();
    }
}

Order* NVKMainWindow::order() const
{
    return m_order;
}

void NVKMainWindow::showEvent(QShowEvent *event)
{
#ifdef Q_OS_ANDROID
    showFullScreen();
#else
    show();
#endif
    setupViews();
    emit shown();
    QMainWindow::showEvent(event);
}

void NVKMainWindow::closeEvent(QCloseEvent *event)
{
    emit closing();
    QMainWindow::closeEvent(event);
}

UserPanelScene* NVKMainWindow::userPanelScene() const
{
    return qobject_cast<UserPanelScene*>(m_userPanelView->scene());
}

ProductsScene* NVKMainWindow::productsScene() const
{
    return qobject_cast<ProductsScene*>(m_productsView->scene());
}

CategoriesScene* NVKMainWindow::categoriesScene() const
{
    return qobject_cast<CategoriesScene*>(m_categoriesView->scene());
}

ProductsView* NVKMainWindow::productsView() const
{
    return m_productsView;
}

CategoriesView* NVKMainWindow::categoriesView() const
{
    return m_categoriesView;
}

QComboBox* NVKMainWindow::pageSizeCb() const
{
    return ui->pageSizeComboBox;
}

int NVKMainWindow::currentPage() const
{
    return m_currentPage;
}

QLabel* NVKMainWindow::productsInCategoryLabel() const
{
    return ui->productsInCategoryLabel;
}

QLabel* NVKMainWindow::currentPageLabel() const
{
    return ui->currentPageLabel;
}

QPushButton* NVKMainWindow::nextPageButton() const
{
    return ui->nextPageButton;
}

QPushButton* NVKMainWindow::previousPageButton() const
{
    return ui->previousPageButton;
}

void NVKMainWindow::setPreviousPageExists(bool exists)
{
    m_previousPageExists = exists;
}

void NVKMainWindow::setNextPageExists(bool exists)
{
    m_nextPageExists = exists;
}

void NVKMainWindow::setCurrentPage(const int & page)
{
    m_currentPage = page;
}

bool NVKMainWindow::nextPageExists() const
{
    return m_nextPageExists;
}

bool NVKMainWindow::previousPageExists() const
{
    return m_previousPageExists;
}

