#!/bin/sh
LD_LIBRARY_PATH=/home/wenwei/qt/qtmqtt/build/lib:/home/wenwei/Qt/5.9.2/android_armv7/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
export LD_LIBRARY_PATH
QT_PLUGIN_PATH=/home/wenwei/Qt/5.9.2/android_armv7/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH
exec "$@"
