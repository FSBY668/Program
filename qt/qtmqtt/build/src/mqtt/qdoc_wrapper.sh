#!/bin/sh
QT_VERSION=5.12.1
export QT_VERSION
QT_VER=5.12
export QT_VER
QT_VERSION_TAG=5121
export QT_VERSION_TAG
QT_INSTALL_DOCS=/home/wenwei/Qt/Docs/Qt-5.9.2
export QT_INSTALL_DOCS
BUILDDIR=/home/wenwei/qt/qtmqtt/build/src/mqtt
export BUILDDIR
exec /home/wenwei/Qt/5.9.2/android_armv7/bin/qdoc "$@"
