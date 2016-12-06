#ifndef PRODUCTSEARCHWINDOW_H
#define PRODUCTSEARCHWINDOW_H


#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>

namespace Ui {
class ProductSearchWindow;
}

class ProductSearchWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProductSearchWindow(QWidget *parent = 0);
    ~ProductSearchWindow();
    QComboBox* searchCategoriesComboBox() const;

    QString sortBy() const;
    QString searchTerm() const;
    QPair<double, double> priceInterval() const;
    QStringList categories() const;
    int direction() const;

Q_SIGNALS:
    void search();
private:
    Ui::ProductSearchWindow *ui;
protected:
    void showEvent(QShowEvent* event);
};

#endif // PRODUCTSEARCHWINDOW_H
