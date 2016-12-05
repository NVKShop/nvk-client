#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "backend/User.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

    QString userName() const;
    QString userPassword() const;
private:
    Ui::LoginWindow *ui;

protected:
    void showEvent(QShowEvent *e);
Q_SIGNALS:
    void showForgotUserWindow();
    void loginUser();
    void cancelLogin();
public Q_SLOTS:
    void loginError(const QString& message);
private Q_SLOTS:
    void forgotUserNameClicked();
    void login();
};

#endif // LOGINWINDOW_H
