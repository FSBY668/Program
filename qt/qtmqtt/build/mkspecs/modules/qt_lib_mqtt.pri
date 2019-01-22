QT_MODULE_BIN_BASE = /home/wenwei/qt/qtmqtt/build/bin
QT_MODULE_INCLUDE_BASE = /home/wenwei/qt/qtmqtt/build/include
QT_MODULE_LIB_BASE = /home/wenwei/qt/qtmqtt/build/lib
QT_MODULE_HOST_LIB_BASE = /home/wenwei/qt/qtmqtt/build/lib
include(/home/wenwei/qt/qtmqtt/build/mkspecs/modules-inst/qt_lib_mqtt.pri)
QT.mqtt.priority = 1
include(/home/wenwei/qt/qtmqtt/build/mkspecs/modules-inst/qt_lib_mqtt_private.pri)
QT.mqtt_private.priority = 1
