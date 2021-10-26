//
// Created by Finger on 9/30/2021.
//

#ifndef BROWSERPROBE_PASSWORDS_H
#define BROWSERPROBE_PASSWORDS_H

#include <cstdio>
#include <iostream>
#include "parse.h"
#include <vector>
#include "sqlitelib.h"
#include "json.hpp"
#include "base64.h"
#include "decrypt.h"

using namespace std;
using namespace nlohmann;

typedef struct loginData {
    string UserName;
    uint8_t* encryptPass;
    uint8_t* encryptUser;
    string Password;
    string LoginUrl;
    time_t CreateDate;
} BrowserLoginData;

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(BrowserLoginData, UserName, Password, LoginUrl, CreateDate)

typedef std::vector<BrowserLoginData> LoginDataVec;

class passwordData : public Item {
public:
    LoginDataVec loginVecData;

    passwordData(string main, string sub);

    void ChromeParse(uint8_t* secretKey) override;

    void FirefoxParse() override;

    void OutPut(OutputType format, string browser, string dir) override;

private:
    vector<uint8_t*> getFirefoxDecryptKey();

    vector<BrowserLoginData> getFirefoxLoginData();

    void outPutJson(string browser, string dir) override;

    void outPutCsv(string browser, string dir) override;

    void outPutConsole(string browser, string dir) override;
};


#endif //BROWSERPROBE_PASSWORDS_H
