#ifndef NVKMAINWINDOW_H
#define NVKMAINWINDOW_H

#include <QMainWindow>
#include <QMultiMap>
#include <QUrl>
#include <QLabel>
#include <QPushButton>

#include "backend/network/HttpHandler.h"
#include "backend/Order.h"
#include "frontend/views/ProductsView.h"
#include "frontend/views/CategoriesView.h"
#include "frontend/views/UserPanelView.h"

namespace Ui {
class NVKMainWindow;
}


class QComboBox;
class NVKMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NVKMainWindow(QWidget *parent = 0);
    ~NVKMainWindow();
    Order* order() const;
    QList<Category*> categories() const;

    UserPanelScene* userPanelScene() const;
    ProductsScene* productsScene() const;
    CategoriesScene* categoriesScene() const;

    ProductsView* productsView() const;
    CategoriesView* categoriesView() const;

    QLabel* productsInCategoryLabel() const;
    QLabel* currentPageLabel() const;

    bool previousPageExists() const;
    bool nextPageExists() const;

    QPushButton* nextPageButton() const;
    QPushButton* previousPageButton() const;

    QComboBox* pageSizeCb() const;

    void setNextPageExists(bool exists);
    void setPreviousPageExists(bool exists);

    void setCurrentPage(const int& page);

    int currentPage() const;
Q_SIGNALS:
    void closing();
    void searchProductClicked();
    void productDoubleClicked(Product* product);
    void showCart();
    void showSettings();
    void shown();
    void nextPage();
    void previousPage();
    void pageSizeChanged(int idx);
private Q_SLOTS:
protected:
    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent *event);
    void keyPressEvent(QKeyEvent* e);

private:
    void setupViews();
    Ui::NVKMainWindow *ui;
    ProductsView* m_productsView;
    CategoriesView* m_categoriesView;
    UserPanelView* m_userPanelView;

    int m_currentPage = 1;
    bool m_previousPageExists = false;
    bool m_nextPageExists = false;
    Order* m_order;
    QMultiMap<Category*,Product*> m_categoryMapped;
public Q_SLOTS:

};

#endif // NVKMAINWINDOW_H
