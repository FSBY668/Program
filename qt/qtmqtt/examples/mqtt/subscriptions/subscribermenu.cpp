#include "subscribermenu.h"
#include "ui_subscribermenu.h"
#include <QtWidgets/QMessageBox>
#include "subscriptionwindow.h"
#include <QtMqtt/QMqttClient>

SubscriberMenu::SubscriberMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubscriberMenu)
{
    ui->setupUi(this);

    m_client = new QMqttClient(this); // to check the pointer
    m_client->setHostname("95.114.56.45"/*ui->lineEdit->text()*/);
    m_client->setPort(1883); // to be in config file, or ui ui->spinBoxPort->value()
    m_client->setCleanSession(false);
    m_client->setKeepAlive(7*24*60*60);

    connect(m_client, &QMqttClient::disconnected, this, &SubscriberMenu::brokerDisconnected);
    connect(ui->lineEdit_Sub_Topic, &QLineEdit::textChanged, m_client, &QMqttClient::setHostname);

//    QMqttTopicFilter topic("/#");
//    m_sub = m_client->subscribe(/*ui->lineEdit_Sub_Topic->text()*/topic, 1 /*ui->spinQoS->text().toUInt()*/);
//    if (!m_sub)
//    {
//        QMessageBox::critical(this, QLatin1String("Error"),
//                              QLatin1String("Could not subscribe. Is there a valid connection?"));
//        return;
//    }

    //updateStatus(m_sub->state());
    //connect(m_sub, &QMqttSubscription::messageReceived, this, &SubscriberMenu::updateMessage);
    //connect(m_sub, &QMqttSubscription::stateChanged, this, &SubscriberMenu::updateStatus);
    //connect(ui->pushButton_Unsubscribe, &QAbstractButton::clicked, m_sub, &QMqttSubscription::unsubscribe);
}

SubscriberMenu::~SubscriberMenu()
{
    //m_sub->unsubscribe();
    delete ui;
    delete m_client;
}

//void SubscriberMenu::updateMessage(const QMqttMessage &msg)
//{
//    ui->listWidget_Sub_Messages->addItem(msg.payload());
//}

//void SubscriberMenu::updateStatus(QMqttSubscription::SubscriptionState state)
//{
//    switch (state) {
//    case QMqttSubscription::Unsubscribed:
//        ui->label_Sub_Status->setText(QLatin1String("Unsubscribed"));
//        break;
//    case QMqttSubscription::SubscriptionPending:
//        ui->label_Sub_Status->setText(QLatin1String("Pending"));
//        break;
//    case QMqttSubscription::Subscribed:
//        ui->label_Sub_Status->setText(QLatin1String("Subscribed"));
//        break;
//    case QMqttSubscription::Error:
//        ui->label_Sub_Status->setText(QLatin1String("Error"));
//        break;
//    default:
//        ui->label_Sub_Status->setText(QLatin1String("--Unknown--"));
//        break;
//    }
//}

void SubscriberMenu::brokerDisconnected()
{
    ui->lineEdit_Sub_Host->setEnabled(true);
    ui->pushButton_Sub_Connect->setText(tr("Connect"));

    ui->lineEdit_Sub_Host->setEnabled(false);
    ui->pushButton_Sub_Connect->setText(tr("Disconnect"));
}

void SubscriberMenu::on_pushButton_Sub_Connect_clicked()
{
    if (m_client->state() == QMqttClient::Disconnected)
    {
        ui->lineEdit_Sub_Host->setEnabled(false);
        ui->pushButton_Sub_Connect->setText(tr("Disconnect"));
        m_client->connectToHost();
    }
    else
    {
        ui->lineEdit_Sub_Host->setEnabled(true);
        ui->pushButton_Sub_Connect->setText(tr("Connect"));
        m_client->disconnectFromHost();
    }
}

//void SubscriberMenu::on_pushButton_Unsubscribe_clicked()
//{
//    m_sub = m_client->subscribe(ui->lineEdit_Sub_Topic->text(), 1 /*ui->spinQoS->text().toUInt()*/);
//    if (!m_sub)
//    {
//        QMessageBox::critical(this, QLatin1String("Error"),
//                              QLatin1String("Could not subscribe. Is there a valid connection?"));
//        return;
//    }
//}

void SubscriberMenu::on_pushButton_Subscribe_clicked()
{
    auto subscription = m_client->subscribe(ui->lineEdit_Sub_Topic->text(), 1 /*ui->spinQoS->text().toUInt()*/);
    if (!subscription)
    {
        QMessageBox::critical(this,
                              QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
        return;
    }

    auto subWindow = new SubscriptionWindow(subscription/*, this*/);
    subWindow->setWindowTitle(subscription->topic().filter());
    subWindow->show();
}

void SubscriberMenu::on_pushButton_clicked()
{
    close();
}
