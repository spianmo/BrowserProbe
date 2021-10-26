//
// Created by Finger on 9/30/2021.
//

#include "cookies.h"

cookies::cookies(string main, string sub) {
    this->mainPath = std::move(main);
}

void cookies::ChromeParse(uint8_t* secretKey) {
    auto db = sqlitelib::Sqlite(ChromeCookieFile);
    auto rows = db.execute<string, uint8_t*, string, string, sqlite_int64, sqlite_int64, int, int, int, int>(
            queryChromiumCookie);
    for (const auto &[key, encryptValue, host, path, createDate, expireDate, isSecure, isHttpOnly, hasExpire, isPersistent]:rows) {
        BrowserCookie cookie = {
                .Host = host,
                .Path = path,
                .KeyName = key,
                .encryptValue = encryptValue,
                .IsSecure = IntToBool(isSecure),
                .IsHTTPOnly = IntToBool(isHttpOnly),
                .HasExpire = IntToBool(hasExpire),
                .IsPersistent = IntToBool(isPersistent),
                .CreateDate = TimeEpochFormat(createDate),
                .ExpireDate = TimeEpochFormat(expireDate)};

        if (secretKey == nullptr){
            //TODO: cookie.Value = decrypt::DPApi(encryptValue);
        }else{
            //TODO: cookie.Value = decrypt::ChromePass(secretKey, encryptValue);
        }

        vector<BrowserCookie> vector_cookie;
        if (cookiesData.contains(host)) {
            vector_cookie = cookiesData.at(host);
            vector_cookie.push_back(cookie);
        } else {
            cookiesData.insert(pair<string, vector<BrowserCookie>>(host, vector_cookie));
        }
    }
}

void cookies::FirefoxParse() {
    auto db = sqlitelib::Sqlite(FirefoxCookieFile);
    auto rows = db.execute<string, string, string, string, sqlite_int64, sqlite_int64, int, int>(
            queryFirefoxCookie);
    for (const auto &[key, value, host, path, creationTime, expireTime, isSecure, isHttpOnly]:rows) {
        BrowserCookie cookie = {
                .Host = host,
                .Path = path,
                .KeyName = key,
                .Value = value,
                .IsSecure = IntToBool(isSecure),
                .IsHTTPOnly = IntToBool(isHttpOnly),
                .CreateDate = TimeEpochFormat(creationTime),
                .ExpireDate = TimeEpochFormat(expireTime)};

        vector<BrowserCookie> vector_cookie;
        if (cookiesData.contains(host)) {
            vector_cookie = cookiesData.at(host);
            vector_cookie.push_back(cookie);
        } else {
            cookiesData.insert(pair<string, vector<BrowserCookie>>(host, vector_cookie));
        }
    }
}

void cookies::OutPut(OutputType format, string browser, string dir) {
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

void cookies::outPutJson(string browser, string dir) {
    string filename = FormatFileName(dir, browser, "cookie", "json");
    json jsonObject = cookiesData;
    WriteFile(filename, jsonObject.dump(4).c_str());
}

void cookies::outPutCsv(string browser, string dir) {
    //TODO:outPutCsv
}

void cookies::outPutConsole(string browser, string dir) {
    json jsonObject = cookiesData;
    cout << jsonObject.dump(4).c_str() << endl;
}

