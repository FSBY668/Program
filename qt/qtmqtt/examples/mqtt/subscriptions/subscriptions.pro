QT       += core gui network widgets mqtt

TARGET = mqttsubscriptions

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    subscriptionwindow.cpp \
    selectionmenu.cpp \
    publishermenu.cpp \
    subscribermenu.cpp \
    registrationmenu.cpp \
    configuration.cpp

HEADERS  += mainwindow.h \
    subscriptionwindow.h \
    selectionmenu.h \
    publishermenu.h \
    subscribermenu.h \
    registrationmenu.h \
    version.h \
    configuration.h \
    defines.h
FORMS    += mainwindow.ui \
    subscriptionwindow.ui \
    selectionmenu.ui \
    publishermenu.ui \
    subscribermenu.ui \
    registrationmenu.ui

target.path = $$[QT_INSTALL_EXAMPLES]/mqtt/subscriptions
INSTALLS += target

CONFIG += c++11

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    user

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
