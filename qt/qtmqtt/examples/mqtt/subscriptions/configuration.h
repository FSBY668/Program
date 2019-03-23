#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QTextStream>

enum EConfigAttribute
{
    eUserFilePath,
    eBrokerIP_Publisher,
    eBrokerIP_Subscriber,
    eMqttPort_Publisher,
    eMqttPort_Subscriber,
    eCleanSession_Publisher,
    eCleanSession_Subscriber,
    eKeepAlive_Publisher,
    eKeepAlive_Subscriber,
    eQoS_Publisher,
    eQoS_Subscriber,
    eRetain_Publisher,
    eRetain_Subscriber
};

class Configuration
{
public:
    Configuration(QString configFilePath);
    ~Configuration();

    QString getConfigAttribute(EConfigAttribute e);
    QString getConfigAttributeName(EConfigAttribute e);

private:
    QString m_ConfigFilePath;
};

#endif // CONFIGURATION_H
