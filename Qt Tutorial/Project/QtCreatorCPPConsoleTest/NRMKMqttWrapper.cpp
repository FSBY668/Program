#include <iostream>
#include "NRMKMqttWrapper.h"

NRMKMqttWrapper::NRMKMqttWrapper(const char *id, const char *host, int port) : mosquittopp(id)
{
        mosqpp::lib_init();			// Initialize libmosquitto

        int keepalive = 120; // seconds
        connect(host, port, keepalive);		// Connect to MQTT Broker
}

void NRMKMqttWrapper::on_connect(int rc)
{
        std::cout << "Connected with code %d. \n" << rc;

        if (rc == 0)
        {
                subscribe(NULL, "command/IGot");
        }
}

void NRMKMqttWrapper::on_subcribe(int mid, int qos_count, const int *granted_qos)
{
        std::cout << "Subscription succeeded. \n";
}
