#ifndef PRODUCTPREVIEWCONTROLLER_H
#define PRODUCTPREVIEWCONTROLLER_H

#include "backend/ProductProperty.h"
#include "backend/graphics_items/Product.h"
#include "frontend/widgets/ProductPreviewDialog.h"

#include <QObject>

class ProductPreviewController : public QObject
{
    Q_OBJECT
public:
    explicit ProductPreviewController(QObject *parent = 0);
    ProductPreviewDialog* view() const;
    void setProduct(Product* product);

    Product* product() const;
    ~ProductPreviewController();
Q_SIGNALS:
    void addToCart(Product* product);
    void addedToCart();
public Q_SLOTS:

private Q_SLOTS:
    void emitAddToCart();
private:
    ProductPreviewDialog* m_productPreviewDialog;
    Product* m_product;
};

#endif // PRODUCTPREVIEWCONTROLLER_H
