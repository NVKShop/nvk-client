#ifndef USERSETTINGSWINDOW_H
#define USERSETTINGSWINDOW_H

#include <QWidget>

namespace Ui {
class UserSettingsWindow;
}

class UserSettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserSettingsWindow(QWidget *parent = 0);
    ~UserSettingsWindow();

private:
    Ui::UserSettingsWindow *ui;
};

#endif // USERSETTINGSWINDOW_H