#ifndef PRODUCTSEARCHCONTROLLER_H
#define PRODUCTSEARCHCONTROLLER_H

#include <QObject>

class ProductSearchController : public QObject
{
    Q_OBJECT
public:
    explicit ProductSearchController(QObject *parent = 0);

signals:

public slots:
};

#endif // PRODUCTSEARCHCONTROLLER_H