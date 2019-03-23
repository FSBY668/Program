#include "configuration.h"
#include <QtWidgets/QMessageBox>
#include <QFile>
#include <QDialog>
//#include <QFileDialog>

Configuration::Configuration(QString configFilePath)
    : m_ConfigFilePath(configFilePath)
{
}

Configuration::~Configuration()
{
}

QString Configuration::getConfigAttribute(EConfigAttribute e)
{
    QFile file(m_ConfigFilePath);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        return "";
    }
    QTextStream in(&file);

    QString strAttributeName = getConfigAttributeName(e);
    QString strAttributeValue = "";

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList lineList = line.split('=', QString::SkipEmptyParts);

        if (lineList.size() > 1)
        {
            if (strAttributeName == lineList[0])
            {
                strAttributeValue = lineList[1];
                break;
            }
        }
    }

    file.close();
    return strAttributeValue;
}

QString Configuration::getConfigAttributeName(EConfigAttribute e)
{
    QString res = "";

    switch (e)
    {
        case EConfigAttribute::eUserFilePath:
        {
            res = "UserFilePath";
        }
        break;
        case EConfigAttribute::eBrokerIP_Publisher:
        {
            res = "BrokerIP_Publisher";
        }
        break;
        case EConfigAttribute::eBrokerIP_Subscriber:
        {
            res = "BrokerIP_Subscriber";
        }
        break;
        case EConfigAttribute::eMqttPort_Publisher:
        {
            res = "MqttPort_Publisher";
        }
        break;
        case EConfigAttribute::eMqttPort_Subscriber:
        {
            res = "MqttPort_Subscriber";
        }
        break;
        case EConfigAttribute::eCleanSession_Publisher:
        {
            res = "CleanSession_Publisher";
        }
        break;
        case EConfigAttribute::eCleanSession_Subscriber:
        {
            res = "CleanSession_Subscriber";
        }
        break;
        case EConfigAttribute::eKeepAlive_Publisher:
        {
            res = "KeepAlive_Publisher";
        }
        break;
        case EConfigAttribute::eKeepAlive_Subscriber:
        {
            res = "KeepAlive_Subscriber";
        }
        break;
        case EConfigAttribute::eQoS_Publisher:
        {
            res = "QoS_Publisher";
        }
        break;
        case EConfigAttribute::eQoS_Subscriber:
        {
            res = "QoS_Subscriber";
        }
        break;
        case EConfigAttribute::eRetain_Publisher:
        {
            res = "Retain_Publisher";
        }
        break;
        case EConfigAttribute::eRetain_Subscriber:
        {
            res = "Retain_Subscriber";
        }
        break;
        default:
        {
            res = "";
        }
        break;
    }

    return res;
}
