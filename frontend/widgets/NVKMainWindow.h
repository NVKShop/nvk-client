#ifndef NVKMAINWINDOW_H
#define NVKMAINWINDOW_H

#include <QMainWindow>
#include <QMultiMap>

#include "backend/Order.h"
#include "frontend/views/ProductsView.h"
#include "frontend/views/CategoriesView.h"
#include "frontend/views/UserPanelView.h"

namespace Ui {
class NVKMainWindow;
}

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
Q_SIGNALS:
    void closing();
    void searchProductClicked();
    void productDoubleClicked(Product* product);
    void showCart();
    void showSettings();
    void shown();
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

    Order* m_order;
    QMultiMap<Category*,Product*> m_categoryMapped;
public Q_SLOTS:
    void categoryChanged(Category* newCategory);

};

#endif // NVKMAINWINDOW_H
