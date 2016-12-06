#include "ProductSearchWindow.h"
#include "ui_productsearchwindow.h"
#include <QDesktopWidget>
#include <QStandardItemModel>
#include <QStandardItem>

ProductSearchWindow::ProductSearchWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductSearchWindow)
{
    ui->setupUi(this);

    connect(ui->cancelButton, &QPushButton::clicked, this, &ProductSearchWindow::close);
    connect(ui->searchButton, &QPushButton::clicked, this, &ProductSearchWindow::search);
#ifndef Q_OS_ANDROID
    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter,
                                          size(), qApp->desktop()->availableGeometry()));
#endif
    ui->categoriesComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
    QPalette p(palette());
    setAutoFillBackground(true);
    p.setColor(QPalette::Background, QColor::fromRgb(0x42, 0x41, 0x3D));
    setPalette(p);

    QPalette pt(ui->label->palette());
    pt.setColor(QPalette::WindowText, QColor::fromRgb(0xFF, 0xCE,0x2B));
    ui->label->setPalette(pt);
    ui->label_2->setPalette(pt);
    ui->label_3->setPalette(pt);
    ui->label_4->setPalette(pt);
    ui->label_5->setPalette(pt);
    ui->label_6->setPalette(pt);

    ui->searchButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
      "stop: 0 white, stop: 1 grey);"
      "border-style: solid;"
      "border-width: 2px;"
      "border-color: black;"
      "border-radius: 15px;}"));
    ui->cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
      "stop: 0 white, stop: 1 grey);"
      "border-style: solid;"
      "border-width: 2px;"
      "border-color: black;"
      "border-radius: 15px;}"));
}

ProductSearchWindow::~ProductSearchWindow()
{
    delete ui;
}

QComboBox* ProductSearchWindow::searchCategoriesComboBox() const
{
    return ui->categoriesComboBox;
}

QString ProductSearchWindow::searchTerm() const
{
    return ui->searchTermLineEdit->text();
}

QString ProductSearchWindow::sortBy() const
{
    return ui->sortByComboBox->currentText();
}

int ProductSearchWindow::direction() const
{
    return ui->searchDirectionComboBox->currentIndex();
}

QStringList ProductSearchWindow::categories() const
{
    QStringList categories;
    QStandardItemModel* model = static_cast<QStandardItemModel*>(ui->categoriesComboBox->model());
    QStandardItem* item;
    for (int row = 0; row < model->rowCount(); ++row)
    {
        item = model->item(row);
        if (item->checkState() == Qt::Checked)
        {
            categories << item->text();
        }
    }

    return categories;
}

QPair<double, double> ProductSearchWindow::priceInterval() const
{
    return QPair<double, double>(ui->lowerLimitSpinBox->value(), ui->upperLimitSpinBox->value());
}

void ProductSearchWindow::showEvent(QShowEvent *event)
{
#ifdef Q_OS_ANDROID
    showFullScreen();
#else
    show();
#endif
    QWidget::showEvent(event);
}

