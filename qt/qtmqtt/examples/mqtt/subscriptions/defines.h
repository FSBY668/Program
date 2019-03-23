#ifndef DEFINES_H
#define DEFINES_H

#include <QString>

// config file path, config file name should be fixed with "config.cfg"
// config file location should be in the local build folder
const QString strConfigFilePath = "config.cfg";

// this file saves the current remembered user login information
// the content of this file will be replaced with the new user login information,
// when a new user login
// file name should be fixed with "user.cache"
// file location should be in the local build folder
const QString strUserLoginCacheFile = "user.cache";

#endif // DEFINES_H
