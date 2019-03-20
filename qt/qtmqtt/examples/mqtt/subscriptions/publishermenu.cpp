#include "publishermenu.h"
#include "ui_publishermenu.h"
#include <QtCore/QDateTime>
#include <QtWidgets/QMessageBox>

PublisherMenu::PublisherMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PublisherMenu)
{
    if (ui)
    {
        ui->setupUi(this);

        m_client = new QMqttClient(this); // to check the pointer
        if (m_client)
        {
            m_client->setHostname("95.115.106.113"/*ui->lineEdit->text()*/); // to be in the config file
            m_client->setPort(1883); // to be in config file, or ui ui->spinBoxPort->value()
            m_client->setCleanSession(false);
            m_client->setKeepAlive(60);

            //connect(m_client, &QMqttClient::stateChanged, this, &PublisherMenu::updateLogStateChange);
            connect(m_client, &QMqttClient::disconnected, this, &PublisherMenu::brokerDisconnected);

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

            connect(ui->lineEdit_Pub_Host, &QLineEdit::textChanged, m_client, &QMqttClient::setHostname);
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
}

void PublisherMenu::on_pushButton_Pub_Connect_clicked()
{
    if (m_client->state() == QMqttClient::Disconnected)
    {
        ui->lineEdit_Pub_Host->setEnabled(false);
        ui->pushButton_Pub_Connect->setText(tr("Disconnect"));
        m_client->connectToHost();
    }
    else
    {
        ui->lineEdit_Pub_Host->setEnabled(true);
        ui->pushButton_Pub_Connect->setText(tr("Connect"));
        m_client->disconnectFromHost();
    }
}

void PublisherMenu::brokerDisconnected()
{
    ui->lineEdit_Pub_Host->setEnabled(true);
    ui->pushButton_Pub_Connect->setText(tr("Connect"));

    ui->lineEdit_Pub_Host->setEnabled(false);
    ui->pushButton_Pub_Connect->setText(tr("Disconnect"));
}

void PublisherMenu::on_pushButton_Pub_Publish_clicked()
{
    if (m_client->publish(ui->lineEdit_Pub_Topic->text(),
                          ui->plainTextEdit_Pub_Message->toPlainText().toUtf8(),
                          1 /*ui->spinQoS_2->text().toUInt()*/,
                          true /*ui->checkBoxRetain->isChecked()*/) == -1)
    {
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
    }
}

void PublisherMenu::on_pushButton_clicked()
{
    close();
}
