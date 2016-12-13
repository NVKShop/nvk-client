#ifndef PRODUCTSEARCHCONTROLLER_H
#define PRODUCTSEARCHCONTROLLER_H

#include "frontend/widgets/ProductSearchWindow.h"
#include "backend/ProductSearch.h"

#include <QObject>

class ProductSearchController : public QObject
{
    Q_OBJECT
public:
    explicit ProductSearchController(QObject *parent = 0);
    ProductSearchWindow* view() const;
    ~ProductSearchController();
    bool searchedAlready();
    void setCategories(const QStringList& categories);
Q_SIGNALS:
    void searchProduct(ProductSearch* search);
    void searchDataOk();
public Q_SLOTS:
    void search();
    void searched();
private:
    ProductSearchWindow* m_productSearchWindow;
    bool m_searchedAlready;
};

#endif // PRODUCTSEARCHCONTROLLER_H
