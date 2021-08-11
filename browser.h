//
// Created by Finger on 8/6/2021.
//

#ifndef BROWSERPROBE_BROWSER_H
#define BROWSERPROBE_BROWSER_H

#include <string>
#include "parse.h"
#include <map>
#include <vector>

#define chromeName         "Chrome"
#define chromeBetaName     "Chrome Beta"
#define chromiumName       "Chromium"
#define edgeName           "Microsoft Edge"
#define firefoxName        "Firefox"
#define firefoxBetaName    "Firefox Beta"
#define firefoxDevName     "Firefox Dev"
#define firefoxNightlyName "Firefox Nightly"
#define firefoxESRName     "Firefox ESR"
#define speed360Name       "360speed"
#define qqBrowserName      "qq"
#define braveName          "Brave"
#define operaName          "Opera"
#define operaGXName        "OperaGX"
#define vivaldiName        "Vivaldi"

#define cookie     "cookie"
#define history    "history"
#define bookmark   "bookmark"
#define download   "download"
#define password   "password"
#define creditcard "creditcard"

#define errItemNotSupported    "item not supported, default is 'all', choose from history|download|password|bookmark|cookie"
#define errBrowserNotSupported "browser not supported")
#define errChromeSecretIsEmpty "chrome secret is empty")
#define errDbusSecretIsEmpty   "dbus secret key is empty")
#define errBase64DecodeFailed "decode base64 failed"
using namespace std;

class Browser;

typedef Browser *(*New)(std::string &, std::string &, std::string &, std::string &);

struct BrowserConfig {
    string ProfilePath;
    string Name;
    string KeyPath;
    string Storage;
    New New;
};

class Browser {
public:
    virtual void InitSecretKey() = 0;

    virtual string GetName() = 0;

    virtual char *GetSecretKey() = 0;

    virtual vector<Item *> GetAllItems() = 0;

    virtual Item *GetItem(string itemName) = 0;

    static string USERPROFILE;
    static map<string, BrowserConfig> browserList;
};


#endif //BROWSERPROBE_BROWSER_H
