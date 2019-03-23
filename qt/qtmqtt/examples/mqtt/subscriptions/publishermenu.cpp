#include "defines.h"
#include "publishermenu.h"
#include "ui_publishermenu.h"
#include <QtCore/QDateTime>
#include <QtWidgets/QMessageBox>

PublisherMenu::PublisherMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PublisherMenu)
{
    m_config = new Configuration(strConfigFilePath);

    if (ui)
    {
        ui->setupUi(this);

        m_client = new QMqttClient(this);
        if (m_client && m_config)
        {
            m_client->setHostname(m_config->getConfigAttribute(EConfigAttribute::eBrokerIP_Publisher));
            m_client->setPort((m_config->getConfigAttribute(EConfigAttribute::eMqttPort_Publisher)).toInt());
            QString strCleanSession = m_config->getConfigAttribute(EConfigAttribute::eCleanSession_Publisher);
            QVariant temp = strCleanSession;
            bool bCleanSession = temp.toBool();
            m_client->setCleanSession(bCleanSession);
            m_client->setKeepAlive((m_config->getConfigAttribute(EConfigAttribute::eKeepAlive_Publisher)).toInt());

            //connect(m_client, &QMqttClient::stateChanged, this, &PublisherMenu::updateLogStateChange);
            //connect(m_client, &QMqttClient::disconnected, this, &PublisherMenu::brokerDisconnected);

            //    connect(m_client, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
            //        const QString content = QDateTime::currentDateTime().toString()
            //                + QLatin1String(" Received Topic: ")
            //                + topic.name()
            //                + QLatin1String(" Message: ")
            //                + message
            //                + QLatin1Char('\n');
            //        ui->editLog->insertPlainText(content);
            //    });

            //    connect(m_client, &QMqttClient::pingResponseReceived, this, [this]() {
            //        ui->buttonPing->setEnabled(true);
            //        const QString content = QDateTime::currentDateTime().toString()
            //                + QLatin1String(" PingResponse")
            //                + QLatin1Char('\n');
            //        ui->editLog->insertPlainText(content);
            //    });

            //connect(ui->lineEdit_Pub_Host, &QLineEdit::textChanged, m_client, &QMqttClient::setHostname);
            //connect(ui->spinBoxPort, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::setClientPort);
            //connect(ui->lineEditUser, &QLineEdit::textChanged, m_client, &QMqttClient::setUsername);
            //connect(ui->lineEditPassword, &QLineEdit::textChanged, m_client, &QMqttClient::setPassword);
            //updateLogStateChange();
        }
    }
}

PublisherMenu::~PublisherMenu()
{
    delete ui;
    delete m_client;
    delete m_config;
}

void PublisherMenu::on_pushButton_Pub_Connect_clicked()
{
    if (m_client->state() == QMqttClient::Disconnected)
    {
        //ui->lineEdit_Pub_Host->setEnabled(false);
        ui->pushButton_Pub_Connect->setText(tr("Disconnect from Mqtt Broker"));
        m_client->connectToHost();
    }
    else
    {
        //ui->lineEdit_Pub_Host->setEnabled(true);
        ui->pushButton_Pub_Connect->setText(tr("Connect to Mqtt Broker"));
        m_client->disconnectFromHost();
    }
}

//void PublisherMenu::brokerDisconnected()
//{
//    if (m_client->state() == QMqttClient::Disconnected)
//    {
//        //ui->lineEdit_Pub_Host->setEnabled(true);
//        ui->pushButton_Pub_Connect->setText(tr("Disconnect from Mqtt Broker"));
//    }
//    else
//    {
//        //ui->lineEdit_Pub_Host->setEnabled(false);
//        ui->pushButton_Pub_Connect->setText(tr("Connect to Mqtt Broker"));
//    }
//}

void PublisherMenu::on_pushButton_Pub_Publish_clicked()
{
    if (!m_config)
    {
        return;
    }

    QString strRetain = m_config->getConfigAttribute(EConfigAttribute::eRetain_Publisher);
    QVariant temp = strRetain;
    bool bRetain = temp.toBool();

    if (m_client->publish(ui->lineEdit_Pub_Topic->text(),
                          ui->plainTextEdit_Pub_Message->toPlainText().toUtf8(),
                          (m_config->getConfigAttribute(EConfigAttribute::eQoS_Publisher)).toInt(),
                          bRetain) == -1)
    {
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
    }
}

void PublisherMenu::on_pushButton_clicked()
{
    close();
}
