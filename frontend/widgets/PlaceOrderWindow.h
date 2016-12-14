#ifndef PLACEORDERWINDOW_H
#define PLACEORDERWINDOW_H

#include <QDialog>
#include "backend/Order.h"

namespace Ui {
class PlaceOrderWindow;
}

class QTableWidget;
class PlaceOrderWindow : public QDialog
{
    Q_OBJECT
public:
    explicit PlaceOrderWindow(QWidget *parent = 0);
    ~PlaceOrderWindow();
    void setOrder(Order* order);
    Order* order() const;
    QTableWidget* cartTableWidget() const;

private:
    Ui::PlaceOrderWindow *ui;
    Order* m_order;
private Q_SLOTS:

    void cartCellChangedSlot(int val);
protected:
    void showEvent(QShowEvent* e) Q_DECL_OVERRIDE;
Q_SIGNALS:
    void placeOrderButtonClicked();
    void resetCart();
    void cartCellChanged(int row, int val);
};

#endif // PLACEORDERWINDOW_H
