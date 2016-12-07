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

    bool hasChanges() const;
    bool emailChanged() const;
    bool addressChanged() const;
    bool firstNameChanged() const;
    bool lastNameChanged() const;
    bool phoneNumberChanged() const;
private:
    Ui::UserSettingsWindow *ui;

    bool m_hasChanges;

    bool m_emailChanged;
    bool m_firstNameChanged;
    bool m_lastNameChanged;
    bool m_addressChanged;
    bool m_phoneNumberChanged;
private Q_SLOTS:
    void addressChangedSomewhere();
    void emailTextChanged();
    void phoneNumberTextChanged();
    void firstNameTextChanged();
    void lastNameTextChanged();
protected:
    void showEvent(QShowEvent* event) Q_DECL_OVERRIDE;

Q_SIGNALS:
    void saveSettingsButtonClicked();
};

#endif // USERSETTINGSWINDOW_H
