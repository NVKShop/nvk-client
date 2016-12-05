#ifndef PRODUCTPREVIEWCONTROLLER_H
#define PRODUCTPREVIEWCONTROLLER_H

#include "frontend/widgets/ProductPreviewDialog.h"

#include <QObject>

class ProductPreviewController : public QObject
{
    Q_OBJECT
public:
    explicit ProductPreviewController(QObject *parent = 0);
    ProductPreviewDialog* view() const;
Q_SIGNALS:

public Q_SLOTS:

private:
    ProductPreviewDialog* m_productPreviewDialog;
};

#endif // PRODUCTPREVIEWCONTROLLER_H
