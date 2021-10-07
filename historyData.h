//
// Created by Finger on 9/30/2021.
//

#ifndef BROWSERPROBE_HISTORYDATA_H
#define BROWSERPROBE_HISTORYDATA_H

#include <cstdio>
#include <iostream>
#include "parse.h"
#include <vector>
#include "sqlitelib.h"
#include "json.hpp"

using namespace std;
using namespace nlohmann;

typedef struct history{
    string        Title;
    string        Url;
    int           VisitCount;
    time_t        LastVisitTime;
} BrowserHistory;

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(BrowserHistory, Title,Url,VisitCount,LastVisitTime)


typedef std::vector<BrowserHistory> HistoryVec;

class historyData : public Item {
public:
    HistoryVec historyVecData;

    historyData(string main, string sub);

    void ChromeParse(bytes secretKey) override;

    void FirefoxParse() override;

    void OutPut(OutputType format, string browser, string dir) override;

private:

    void outPutJson(string browser, string dir) override;

    void outPutCsv(string browser, string dir) override;

    void outPutConsole(string browser, string dir) override;
};


#endif //BROWSERPROBE_HISTORYDATA_H
