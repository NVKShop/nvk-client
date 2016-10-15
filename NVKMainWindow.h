#ifndef NVKMAINWINDOW_H
#define NVKMAINWINDOW_H

#include <QMainWindow>
#include <NetworkHandler.h>

namespace Ui {
class NVKMainWindow;
}

class NVKMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NVKMainWindow(QWidget *parent = 0);
    ~NVKMainWindow();

private Q_SLOTS:
    void setReplyLabel(const QString& label);
private:
    Ui::NVKMainWindow *ui;
    NetworkHandler* m_NetworkHandler;
};

#endif // NVKMAINWINDOW_H
