#include "selectionmenu.h"
#include "ui_selectionmenu.h"

SelectionMenu::SelectionMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectionMenu)
{
    ui->setupUi(this);
}

SelectionMenu::~SelectionMenu()
{
    delete ui;
}

void SelectionMenu::on_pushButton_Publisher_clicked()
{
    hide();

    publisherMenu = new PublisherMenu(this);
    publisherMenu->show();
}

void SelectionMenu::on_pushButton_Subscriber_clicked()
{
    hide();

    subscriberMenu = new SubscriberMenu(this);
    subscriberMenu->show();
}
