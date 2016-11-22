#ifndef NVKMAINWINDOW_H
#define NVKMAINWINDOW_H

#include <QMainWindow>
#include "NVKController.h"
#include "ProductsView.h"
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
    void setReplyLabel(const QString& label);
    void showMap();
private:
    Ui::NVKMainWindow *ui;
    NetworkHandler* m_NetworkHandler;
    NVKController m_Controller;
    ProductsView* m_ProductsView;

};

#endif // NVKMAINWINDOW_H
