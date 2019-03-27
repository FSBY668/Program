#ifndef PUBLISHERMENU_H
#define PUBLISHERMENU_H

#include "configuration.h"
#include <QDialog>
#include <QTcpSocket>
#include <QtMqtt/QMqttClient>

namespace Ui {
class PublisherMenu;
}

class PublisherMenu : public QDialog
{
    Q_OBJECT

public:
    explicit PublisherMenu(QWidget *parent = 0);
    ~PublisherMenu();

private slots:
    //void brokerDisconnected();
    void on_pushButton_Pub_Publish_clicked();
    void on_pushButton_Pub_Connect_clicked();
    void on_pushButton_clicked();

private:
    Ui::PublisherMenu* ui;
    QMqttClient* m_client;
    Configuration* m_config;
};

#endif // PUBLISHERMENU_H
