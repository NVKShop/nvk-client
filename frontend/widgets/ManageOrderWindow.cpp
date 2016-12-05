#include "frontend/widgets/ManageOrderWindow.h"
#include "ui_manageorderwindow.h"

ManageOrderWindow::ManageOrderWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageOrderWindow)
{
    ui->setupUi(this);
}

ManageOrderWindow::~ManageOrderWindow()
{
    delete ui;
}

void ManageOrderWindow::showEvent(QShowEvent *e)
{
#ifdef Q_OS_ANDROID
    showFullScreen();
#else
    show();
#endif
    QWidget::showEvent(e);
}
