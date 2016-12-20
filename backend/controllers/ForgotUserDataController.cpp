#include "ForgotUserDataController.h"
#include <QMessageBox>
#include <QRegularExpressionMatch>

ForgotUserDataController::ForgotUserDataController(QObject *parent) : QObject(parent),
    m_forgotUserDataWindow(new ForgotUserDataWindow), m_httpHandler(new HttpHandler)
{
    connect(m_forgotUserDataWindow, &ForgotUserDataWindow::forgotUserDataSent,
            this, &ForgotUserDataController::forgotUserData);
    connect(m_httpHandler, &HttpHandler::finished, this, &ForgotUserDataController::successfulReminder);
    connect(m_httpHandler, &HttpHandler::replyErrors, this, &ForgotUserDataController::unsuccessfulReminder);
}

ForgotUserDataWindow* ForgotUserDataController::view() const
{
    return m_forgotUserDataWindow;
}

ForgotUserDataController::~ForgotUserDataController()
{
    delete m_forgotUserDataWindow;
}

void ForgotUserDataController::forgotUserData(const QString &email)
{
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
            // NEW
            QUrl url = HttpHandler::FORGOTTEN_PASSWORD_URL_STRING.arg(email);
            qDebug() << "sending stuff..";
            m_httpHandler->setUrl(url);
            m_httpHandler->sendRequest(QByteArray());
        }
    }
    else
    {
        QMessageBox::warning(0, "Enter an email address", "Error, email address is empty!");
    }
}

void ForgotUserDataController::unsuccessfulReminder(const int &code)
{
    if (code == 400)
    {
        //email nope
        QMessageBox::warning(0, "Error" + QString::number(code),"");
    }
    else if (code == 404)
    {
        //server nope
        QMessageBox::warning(0, "Error" + QString::number(code),"");
    }
    qDebug() << "errorcode: " << QString::number(code);
}

