#ifndef PRODUCTSEARCHWINDOW_H
#define PRODUCTSEARCHWINDOW_H

#include <QWidget>

namespace Ui {
class ProductSearchWindow;
}

class ProductSearchWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProductSearchWindow(QWidget *parent = 0);
    ~ProductSearchWindow();

private:
    Ui::ProductSearchWindow *ui;
};

#endif // PRODUCTSEARCHWINDOW_H
