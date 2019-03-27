#ifndef SUBSCRIBERMENU_H
#define SUBSCRIBERMENU_H

#include "configuration.h"
#include <QDialog>
#include <QTcpSocket>
#include <QtMqtt/QMqttClient>
#include <QtMqtt/QMqttSubscription>

namespace Ui {
class SubscriberMenu;
}

class SubscriberMenu : public QDialog
{
    Q_OBJECT

public:
    explicit SubscriberMenu(QWidget *parent = 0);
    ~SubscriberMenu();

public slots:
    //void updateMessage(const QMqttMessage &msg);
    //void updateStatus(QMqttSubscription::SubscriptionState state);

private slots:
    //void brokerDisconnected();
    void on_pushButton_Sub_Connect_clicked();
    void on_pushButton_Subscribe_clicked();
    void on_pushButton_clicked();

private:
    Ui::SubscriberMenu* ui;
    QMqttClient* m_client;
    Configuration* m_config;
};

#endif // SUBSCRIBERMENU_H
