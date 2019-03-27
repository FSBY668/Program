#include "defines.h"
#include "subscribermenu.h"
#include "ui_subscribermenu.h"
#include <QtWidgets/QMessageBox>
#include "subscriptionwindow.h"
#include <QtMqtt/QMqttClient>

SubscriberMenu::SubscriberMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubscriberMenu)
{
    m_config = new Configuration(strConfigFilePath);

    if (ui)
    {
        ui->setupUi(this);

        m_client = new QMqttClient(this);
        if (m_client && m_config)
        {
            m_client->setHostname(m_config->getConfigAttribute(EConfigAttribute::eBrokerIP_Subscriber));
            m_client->setPort((m_config->getConfigAttribute(EConfigAttribute::eMqttPort_Subscriber)).toInt());
            QString strCleanSession = m_config->getConfigAttribute(EConfigAttribute::eCleanSession_Subscriber);
            QVariant temp = strCleanSession;
            bool bCleanSession = temp.toBool();
            m_client->setCleanSession(bCleanSession);
            m_client->setKeepAlive((m_config->getConfigAttribute(EConfigAttribute::eKeepAlive_Subscriber)).toLong());

            //connect(m_client, &QMqttClient::disconnected, this, &SubscriberMenu::brokerDisconnected);
            connect(ui->lineEdit_Sub_Topic, &QLineEdit::textChanged, m_client, &QMqttClient::setHostname);

            //updateStatus(m_sub->state());
            //connect(m_sub, &QMqttSubscription::messageReceived, this, &SubscriberMenu::updateMessage);
            //connect(m_sub, &QMqttSubscription::stateChanged, this, &SubscriberMenu::updateStatus);
            //connect(ui->pushButton_Unsubscribe, &QAbstractButton::clicked, m_sub, &QMqttSubscription::unsubscribe);
        }
    }
}

SubscriberMenu::~SubscriberMenu()
{
    delete ui;
    delete m_client;
    delete m_config;
}

//void SubscriberMenu::brokerDisconnected()
//{
//    if (m_client->state() == QMqttClient::Disconnected)
//    {
//        //ui->lineEdit_Sub_Host->setEnabled(true);
//        ui->pushButton_Sub_Connect->setText(tr("Disconnect from Mqtt Broker"));
//    }
//    else
//    {
//        //ui->lineEdit_Sub_Host->setEnabled(false);
//        ui->pushButton_Sub_Connect->setText(tr("Connect to Mqtt Broker"));
//    }
//}

void SubscriberMenu::on_pushButton_Sub_Connect_clicked()
{
    if (m_client->state() == QMqttClient::Disconnected)
    {
        //ui->lineEdit_Sub_Host->setEnabled(false);
        ui->pushButton_Sub_Connect->setText(tr("Disconnect from Mqtt Broker"));
        m_client->connectToHost();
    }
    else
    {
        //ui->lineEdit_Sub_Host->setEnabled(true);
        ui->pushButton_Sub_Connect->setText(tr("Connect to Mqtt Broker"));
        m_client->disconnectFromHost();
    }
}

void SubscriberMenu::on_pushButton_Subscribe_clicked()
{
    auto subscription = m_client->subscribe(ui->lineEdit_Sub_Topic->text(),
        (m_config->getConfigAttribute(EConfigAttribute::eQoS_Subscriber)).toInt());
    if (!subscription)
    {
        QMessageBox::critical(this,
            QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
        return;
    }

    auto subWindow = new SubscriptionWindow(subscription);
    subWindow->setWindowTitle(subscription->topic().filter());
    subWindow->show();
}

void SubscriberMenu::on_pushButton_clicked()
{
    close();
}
