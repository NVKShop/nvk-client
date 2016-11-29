#ifndef NVKMAINWINDOW_H
#define NVKMAINWINDOW_H

#include <QMainWindow>
#include "ProductsView.h"
#include "CategoriesView.h"
#include "UserPanelView.h"
#include "Order.h"

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
private Q_SLOTS:

protected:
    void showEvent(QShowEvent *event);
private:
    void setupViews();
    Ui::NVKMainWindow *ui;
    ProductsView* m_productsView;
    CategoriesView* m_categoriesView;
    UserPanelView* m_userPanelView;

    Order* m_order;

    void keyPressEvent(QKeyEvent* e);

};

#endif // NVKMAINWINDOW_H
