#ifndef PLACEORDERWINDOW_H
#define PLACEORDERWINDOW_H

#include <QDialog>

namespace Ui {
class PlaceOrderWindow;
}

class PlaceOrderWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PlaceOrderWindow(QWidget *parent = 0);
    ~PlaceOrderWindow();

private:
    Ui::PlaceOrderWindow *ui;
};

#endif // PLACEORDERWINDOW_H
