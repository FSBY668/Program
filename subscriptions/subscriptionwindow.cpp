#include "subscriptionwindow.h"
#include "ui_subscriptionwindow.h"

SubscriptionWindow::SubscriptionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubscriptionWindow)
{
    ui->setupUi(this);
}

SubscriptionWindow::~SubscriptionWindow()
{
    delete ui;
}
