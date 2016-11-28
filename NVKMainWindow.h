#ifndef NVKMAINWINDOW_H
#define NVKMAINWINDOW_H

#include <QMainWindow>
#include "ProductsView.h"
#include "CategoriesView.h"
#include "UserPanelView.h"

namespace Ui {
class NVKMainWindow;
}

class NVKMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NVKMainWindow(QWidget *parent = 0);
    ~NVKMainWindow();

private Q_SLOTS:
private:
    void setupViews();
    Ui::NVKMainWindow *ui;
    ProductsView* m_productsView;
    CategoriesView* m_categoriesView;
    UserPanelView* m_userPanelView;
    void keyPressEvent(QKeyEvent* e);

};

#endif // NVKMAINWINDOW_H
