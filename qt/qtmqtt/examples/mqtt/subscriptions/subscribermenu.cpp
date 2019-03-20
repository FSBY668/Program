#include "subscribermenu.h"
#include "ui_subscribermenu.h"
#include <QtWidgets/QMessageBox>
#include "subscriptionwindow.h"
#include <QtMqtt/QMqttClient>

SubscriberMenu::SubscriberMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubscriberMenu)
{
    if (ui)
    {
        ui->setupUi(this);

        m_client = new QMqttClient(this);
        if (m_client)
        {
            m_client->setHostname("95.115.106.113"/*ui->lineEdit->text()*/);
            m_client->setPort(1883); // to be in config file, or ui ui->spinBoxPort->value()
            m_client->setCleanSession(false);
            m_client->setKeepAlive(7*24*60*60);

            connect(m_client, &QMqttClient::disconnected, this, &SubscriberMenu::brokerDisconnected);
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
}

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
