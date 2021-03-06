// This is the software version file
// Author: Wenwei Gu
// Created on 22.01.2019

#include <QString>

const static QString strVersion = "11";

/*
version 1 2019-01-22
 * Install the Qt 5.9.1 and 5.9.2
 * Download the Android SDK and NDK
 * using IDE QtCreator, set the kits.
 * Download the QtMqtt and make the subscription example run on my PC and on my Android phone
version 2 2019-03-06
 * test with QoS, keep alive and Retain (currently with QoS 2, Retain Yes, keep alive one week)
version 3 2019-03-09
 * create the Android Manifest xml for the project, set the priority to 1000
version 4 2019-03-10
 * set the mqtt client clean session to false for receving the offline published message, client Id is still needed
version 5 2019-03-14
 * seperate the publisher and subscriber (not finsished)
 * login and registion system (not finished)
version 6 2019-03-16
 * seperate the publisher, subscriber and subscription window (continued)
version 7 2019-03-17
 * registration system, write to a file, which should be later stored on the server. Data stored in the file is
   {Username, Password, UserLevel} (continued, not finished)
version 8 2019-03-18
 * change the widget type of subscription window from listWidget to plainTextEdit
 * finish the basic login system
version 9 2019-03-19
 * main menu editline default focus, tab button move to next editline
 * enable/disable the publisher and subscriber button according to the userlevel
 * info box of incomplete registration input DONE
 * Dialog titles
 * back/close/Logout buttons
version 10 2019-03-20
 * clean the code a little bit
version 11 2019-03-23
 * version number show in the main window title bar
 * some code clean
 * config file implemented, so the attributes can be edited before the app starts, Config file
   is located in the local buld folder with fixed name "config.cfg"
 * implemented a checkbox in the login menu, if the the checkbox is checked, will remember the
   current login user info.
version 12 2019-03-27
 * backup the code, prepare for the windows crosscompile 


*/
