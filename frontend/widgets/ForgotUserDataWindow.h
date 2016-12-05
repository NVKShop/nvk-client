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
Q_SIGNALS:
    void forgotUserDataSent(const QString& email);
private:
    Ui::ForgotUserDataWindow *ui;

private Q_SLOTS:
    void forgotUserDataClicked();

protected:
    void showEvent(QShowEvent* e) Q_DECL_OVERRIDE;
};

#endif // FORGOTUSERDATAWINDOW_H
