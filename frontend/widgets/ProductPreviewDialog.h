#ifndef PRODUCTPREVIEWDIALOG_H
#define PRODUCTPREVIEWDIALOG_H

#include <QDialog>

namespace Ui {
class ProductPreviewDialog;
}

class ProductPreviewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProductPreviewDialog(QWidget *parent = 0);
    ~ProductPreviewDialog();

private:
    Ui::ProductPreviewDialog *ui;
};

#endif // PRODUCTPREVIEWDIALOG_H
