#include "ForgotUserDataWindow.h"
#include "ui_forgotuserdatawindow.h"
#include <QMessageBox>
#include <QRegularExpression>

ForgotUserDataWindow::ForgotUserDataWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ForgotUserDataWindow)
{
    ui->setupUi(this);
    connect(ui->sendReminderButton, &QPushButton::clicked, this, &ForgotUserDataWindow::forgotUserData);
}

ForgotUserDataWindow::~ForgotUserDataWindow()
{
    delete ui;
}

void ForgotUserDataWindow::forgotUserData()
{
    QString email = ui->emailAddressLineEdit->text();
    QRegularExpression rex("(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\\.[a-z0-9!#$%&'*+/=?^_`{|}~-"
                "]+)*|\"(?:[\\x01-\\x08\\x0b\\x0c\\x0e-"
                "\\x1f\\x21\\x23-\\x5b\\x5d-\\x7f]|\\\\[\\x01-"
                "\\x09\\x0b\\x0c\\x0e-\\x7f])*\")"
                "@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9]"
                ")?|\\[(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.)"
                "{3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?|[a-z0-9-]*"
                "[a-z0-9]:"
                "(?:[\\x01-\\x08\\x0b\\x0c\\x0e-\\x1f\\x21-\\x5a\\x53-\\x7f]"
                "|\\\\[\\x01-\\x09\\x0b\\x0c\\x0e-\\x7f])+)\\])");

    QRegularExpressionMatch match = rex.match(email);

    if (!email.isEmpty())
    {
        if (!match.hasMatch())
        {
            QMessageBox::warning(0, "Enter a valid address", "Error, email address is invalid");
        }
        else
        {
            // ok, emit..
        }
    }
    QMessageBox::warning(0, "Enter an email address", "Error, email address is empty!");
}
