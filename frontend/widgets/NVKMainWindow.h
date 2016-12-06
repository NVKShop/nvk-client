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
Q_SIGNALS:
    void closing();
    void searchProductClicked();
    void productDoubleClicked(Product* product);

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
private Q_SLOTS:
    void categoryChanged(Category* newCategory);

};

#endif // NVKMAINWINDOW_H
