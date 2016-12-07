#ifndef USERSETTINGSWINDOW_H
#define USERSETTINGSWINDOW_H

#include <QWidget>
#include "User.h"
namespace Ui {
class UserSettingsWindow;
}

class UserSettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserSettingsWindow(QWidget *parent = 0);
    ~UserSettingsWindow();
    void setUser(User* user);
    bool emailSet() const;
private:
    Ui::UserSettingsWindow *ui;
protected:
    void showEvent(QShowEvent* event) Q_DECL_OVERRIDE;

Q_SIGNALS:
    void saveSettingsButtonClicked();
};

#endif // USERSETTINGSWINDOW_H
