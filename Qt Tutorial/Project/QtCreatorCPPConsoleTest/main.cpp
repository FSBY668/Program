#include <iostream>
#include <mosquittopp.h>
#include <mosquitto.h>
#include "NRMKMqttWrapper.h"

//using namespace std;

int main()
{
    std::cout << "Hello World!" << std::endl;


    NRMKMqttWrapper * mqttHdl;
    mqttHdl = new NRMKMqttWrapper("Neuromeka IGot", "127.0.0.1", 1883);

    while(1)
    {
//        fd	= open (NRMK_SMEM_NAME, O_RDWR, S_IRUSR | S_IWUSR);	// Open Shared Memory
//        res	= read(fd, tstr, FILE_LENGTH);

//        for (i=0; i<FILE_LENGTH; ++i)					// Read data from shared memory
//        {
//            if ((tstr[i]==':') && (i<100))
//            {
//                strncpy(strCounter, tstr, i);
//                Counter = atol(strCounter);
//                break;
//            }

//        }

//        if (Counter != preCounter)					// Check whether this data is new
//        {
//            printf ("%s", tstr);
//            preCounter=Counter;

//            mqttHdl->publish(NULL, "IGoT/sensors", strlen(tstr), tstr);	// Publish the data to MQTT topic "IGoT/sensors"
//        }

//        close (fd);

bool        res = mqttHdl->loop();						// Keep MQTT connection
        if (res)
            mqttHdl->reconnect();
//        usleep(1e5);
    }



    return 0;
}
