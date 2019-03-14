#include "subscribermenu.h"
#include "ui_subscribermenu.h"

SubscriberMenu::SubscriberMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubscriberMenu)
{
    ui->setupUi(this);
}

SubscriberMenu::~SubscriberMenu()
{
    delete ui;
}
