//
// Created by Finger on 9/30/2021.
//

#ifndef BROWSERPROBE_COOKIES_H
#define BROWSERPROBE_COOKIES_H

#include <cstdio>
#include <iostream>
#include "parse.h"
#include <vector>
#include "sqlitelib.h"
#include "json.hpp"

using namespace std;
using namespace nlohmann;

typedef struct cookie {
    string Host;
    string Path;
    string KeyName;
    uint8_t* encryptValue;
    string Value;
    bool IsSecure;
    bool IsHTTPOnly;
    bool HasExpire;
    bool IsPersistent;
    time_t CreateDate;
    time_t ExpireDate;
} BrowserCookie;

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(BrowserCookie, Host, Path, KeyName, Value, IsSecure, IsHTTPOnly,
                                   HasExpire, IsPersistent, CreateDate, ExpireDate)

typedef std::map<string,std::vector<BrowserCookie>> CookieMap;

class cookies : public Item {
public:
    CookieMap cookiesData;

    cookies(string main, string sub);

    void ChromeParse(uint8_t* secretKey) override;

    void FirefoxParse() override;

    void OutPut(OutputType format, string browser, string dir) override;

private:

    void outPutJson(string browser, string dir) override;

    void outPutCsv(string browser, string dir) override;

    void outPutConsole(string browser, string dir) override;
};


#endif //BROWSERPROBE_COOKIES_H
