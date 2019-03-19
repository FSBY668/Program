#include "selectionmenu.h"
#include "ui_selectionmenu.h"

SelectionMenu::SelectionMenu(QString userLevel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectionMenu),
    m_userLevel(userLevel)
{
    ui->setupUi(this);

    ui->pushButton_Publisher->setEnabled(true);
    ui->pushButton_Subscriber->setEnabled(true);
    if (m_userLevel == "100")
    {
        ui->pushButton_Publisher->setEnabled(false);
    }
    else if (m_userLevel == "1000")
    {
        ui->pushButton_Subscriber->setEnabled(false);
    }
}

SelectionMenu::~SelectionMenu()
{
    delete ui;
    delete publisherMenu;
    delete subscriberMenu;
}

void SelectionMenu::on_pushButton_Publisher_clicked()
{
    hide();

    publisherMenu = new PublisherMenu(this);
    publisherMenu->setWindowTitle("Publisher"/*subscription->topic().filter()*/);
    publisherMenu->show();
}

void SelectionMenu::on_pushButton_Subscriber_clicked()
{
    hide();

    subscriberMenu = new SubscriberMenu(this);
    subscriberMenu->setWindowTitle("Subscriber"/*subscription->topic().filter()*/);
    subscriberMenu->show();
}

void SelectionMenu::on_pushButton_clicked()
{
    close();
}
