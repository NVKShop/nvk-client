#ifndef FORGOTUSERDATAWINDOW_H
#define FORGOTUSERDATAWINDOW_H

#include <QDialog>

namespace Ui {
class ForgotUserDataWindow;
}

class ForgotUserDataWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ForgotUserDataWindow(QWidget *parent = 0);
    ~ForgotUserDataWindow();

private:
    Ui::ForgotUserDataWindow *ui;

private Q_SLOTS:
    void forgotUserData();
};

#endif // FORGOTUSERDATAWINDOW_H
