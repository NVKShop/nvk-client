#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "User.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;

Q_SIGNALS:
    void showForgotUserWindow();
    void loginUser(User* user);
public Q_SLOTS:

private Q_SLOTS:
    void forgotUserNameClicked();
    void login();
};

#endif // LOGINWINDOW_H
