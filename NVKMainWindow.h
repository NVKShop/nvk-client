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
Q_SIGNALS:
    void closing();
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


};

#endif // NVKMAINWINDOW_H
