#ifndef MANAGEORDERWINDOW_H
#define MANAGEORDERWINDOW_H

#include <QWidget>

namespace Ui {
class ManageOrderWindow;
}

class ManageOrderWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ManageOrderWindow(QWidget *parent = 0);
    ~ManageOrderWindow();

private:
    Ui::ManageOrderWindow *ui;
};

#endif // MANAGEORDERWINDOW_H
