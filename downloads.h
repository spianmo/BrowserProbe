//
// Created by Finger on 9/30/2021.
//

#ifndef BROWSERPROBE_DOWNLOADS_H
#define BROWSERPROBE_DOWNLOADS_H


#include <cstdio>
#include <iostream>
#include "parse.h"
#include <vector>
#include "sqlitelib.h"
#include "json.hpp"

using namespace std;
using namespace nlohmann;

typedef struct download {
    string TargetPath;
    string Url;
    int64_t TotalBytes;
    time_t StartTime;
    time_t EndTime;
    string MimeType;
} BrowserDownload;

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(BrowserDownload, TargetPath, Url, TotalBytes, StartTime, EndTime, MimeType)


typedef std::vector<BrowserDownload> DownloadVec;

class downloads : public Item {
public:
    DownloadVec downloadData;

    downloads(string main, string sub);

    void ChromeParse(uint8_t* secretKey) override;

    void FirefoxParse() override;

    void OutPut(OutputType format, string browser, string dir) override;

private:

    void outPutJson(string browser, string dir) override;

    void outPutCsv(string browser, string dir) override;

    void outPutConsole(string browser, string dir) override;
};


#endif //BROWSERPROBE_DOWNLOADS_H
