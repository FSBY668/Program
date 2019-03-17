// This is the software version file
// Author: Wenwei Gu
// Created on 22.01.2019

const static std::string strVersion = "7";

// version 1 2019-01-22
// * Install the Qt 5.9.1 and 5.9.2
// * Download the Android SDK and NDK
// * using IDE QtCreator, set the kits. 
// * Download the QtMqtt and make the subscription example run on my PC and on my Android phone 
// version 2 2019-03-06
// * test with QoS, keep alive and Retain (currently with QoS 2, Retain Yes, keep alive one week) 
// version 3 2019-03-09
// * create the Android Manifest xml for the project, set the priority to 1000
// version 4 2019-03-10
// * set the mqtt client clean session to false for receving the offline published message, client Id is still needed
// version 5 2019-03-14
// * seperate the publisher and subscriber (not finsished)
// * login and registion system (not finished)
// version 6 2019-03-16
// * seperate the publisher, subscriber and subscription window (continued)
// version 7 2019-03-17
// * registration system, write to a file, which should be later stored on the server. Data stored in the file is 
//	{Username, Password, UserLevel} (continued, not finished)
