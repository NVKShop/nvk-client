#ifndef PRODUCTPREVIEWDIALOG_H
#define PRODUCTPREVIEWDIALOG_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class ProductPreviewDialog;
}

class ProductPreviewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProductPreviewDialog(QWidget *parent = 0);
    ~ProductPreviewDialog();
    QLabel* descriptionLabel() const;
    QLabel* previewLabel() const;
Q_SIGNALS:
    void addToCart();
private:
    Ui::ProductPreviewDialog *ui;
protected:
    void showEvent(QShowEvent* e) Q_DECL_OVERRIDE;
};

#endif // PRODUCTPREVIEWDIALOG_H
