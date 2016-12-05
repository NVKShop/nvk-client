#ifndef PRODUCTSEARCHCONTROLLER_H
#define PRODUCTSEARCHCONTROLLER_H

#include "frontend/widgets/ProductSearchWindow.h"

#include <QObject>

class ProductSearchController : public QObject
{
    Q_OBJECT
public:
    explicit ProductSearchController(QObject *parent = 0);
    ProductSearchWindow* view() const;
Q_SIGNALS:

public Q_SLOTS:

private:
    ProductSearchWindow* m_productSearchWindow;
};

#endif // PRODUCTSEARCHCONTROLLER_H
