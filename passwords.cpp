//
// Created by Finger on 9/30/2021.
//

#include "passwords.h"

passwordData::passwordData(string main, string sub) {
    this->mainPath = std::move(main);
}

void passwordData::ChromeParse(uint8_t* secretKey) {
    auto db = sqlitelib::Sqlite(ChromePasswordFile);
    auto rows = db.execute<string, string, uint8_t*, sqlite_int64>(queryChromiumLogin);
    for (const auto &[url, username, pwd, create]: rows) {
        BrowserLoginData loginData = {
                .UserName = username,
                .encryptPass = pwd,
                .LoginUrl = url
        };
        if (secretKey == nullptr) {
            loginData.Password = reinterpret_cast<const char *const>(decrypt::DPApi(pwd));
        } else {
            loginData.Password = reinterpret_cast<const char *const>(decrypt::ChromePass(secretKey, pwd));
        }
        if (create > time(nullptr)) {
            loginData.CreateDate = TimeEpochFormat(create);
        } else {
            loginData.CreateDate = TimeStampFormat(create);
        }
        loginVecData.push_back(loginData);
    }
}

//get value from key4.db
vector<uint8_t*> passwordData::getFirefoxDecryptKey() {
    vector<uint8_t*> data;
    auto db = sqlitelib::Sqlite(FirefoxKey4File);
    auto pwdRows = db.execute<uint8_t*, uint8_t*>(queryMetaData);
    for (const auto &[item1, item2]: pwdRows) {
        data[0] = item1;
        data[1] = item2;
    }
    auto nssRows = db.execute<uint8_t*, uint8_t*>(queryNssPrivate);
    for (const auto &[a11, a102]: nssRows) {
        data[2] = a11;
        data[3] = a102;
    }
    return data;
}

vector<BrowserLoginData> passwordData::getFirefoxLoginData() {
    string s = ReadFile(FirefoxLoginFile);
    json root = json::parse(s);
    if (root.contains("logins")) {
        json childArray = root["logins"];
        for (auto &child: childArray) {
            BrowserLoginData loginData;
            loginData.LoginUrl = child["formSubmitURL"].get<string>();
            loginData.encryptUser = (uint8_t*) base64::decode(child["encryptedUsername"]).c_str();
            loginData.encryptPass = (uint8_t*) base64::decode(child["encryptedPassword"]).c_str();
            loginData.CreateDate = TimeStampFormat(child["timeCreated"].get<int64_t>());
            loginVecData.push_back(loginData);
        }
    }
    return loginVecData;
}

void passwordData::FirefoxParse() {
    //TODO:FirefoxParse LoginData
}

void passwordData::OutPut(OutputType format, string browser, string dir) {
    switch (format) {
        case JSON:
            outPutJson(browser, dir);
            break;
        case CSV:
            outPutCsv(browser, dir);
            break;
        case CONSOLE:
            outPutConsole(browser, dir);
            break;
    }
}

void passwordData::outPutJson(string browser, string dir) {
    string filename = FormatFileName(dir, browser, "password", "json");
    json jsonObject = loginVecData;
    WriteFile(filename, jsonObject.dump(4).c_str());
}

void passwordData::outPutCsv(string browser, string dir) {
    //TODO:outPutCsv
}

void passwordData::outPutConsole(string browser, string dir) {
    json jsonObject = loginVecData;
    cout << jsonObject.dump(4).c_str() << endl;
}
