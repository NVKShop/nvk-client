#ifndef MANAGEORDERCONTROLLER_H
#define MANAGEORDERCONTROLLER_H

#include "frontend/widgets/ManageOrderWindow.h"

#include <QObject>

class ManageOrderController : public QObject
{
    Q_OBJECT
public:
    explicit ManageOrderController(QObject *parent = 0);
    ManageOrderWindow* view() const;
    ~ManageOrderController();
Q_SIGNALS:

public Q_SLOTS:

private:
    ManageOrderWindow* m_manageOrderWindow;
};

#endif // MANAGEORDERCONTROLLER_H
