#ifndef PLACEORDERWINDOW_H
#define PLACEORDERWINDOW_H

#include <QDialog>
#include "backend/Order.h"

namespace Ui {
class PlaceOrderWindow;
}

class PlaceOrderWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PlaceOrderWindow(QWidget *parent = 0);
    ~PlaceOrderWindow();
    void setOrder(Order* order);
private:
    Ui::PlaceOrderWindow *ui;
    Order* m_order;
protected:
    void showEvent(QShowEvent* e) Q_DECL_OVERRIDE;
};

#endif // PLACEORDERWINDOW_H
