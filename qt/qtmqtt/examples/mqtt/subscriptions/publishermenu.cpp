#include "publishermenu.h"
#include "ui_publishermenu.h"

PublisherMenu::PublisherMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PublisherMenu)
{
    ui->setupUi(this);
}

PublisherMenu::~PublisherMenu()
{
    delete ui;
}
