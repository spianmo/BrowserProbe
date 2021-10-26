//
// Created by Finger on 9/30/2021.
//

#include "historyData.h"

historyData::historyData(string main, string sub) {
    this->mainPath = std::move(main);
}

void historyData::ChromeParse(uint8_t* secretKey) {
    auto db = sqlitelib::Sqlite(ChromeHistoryFile);
    auto rows = db.execute<string, string, int, sqlite_int64>(
            queryChromiumHistory);
    for (const auto &[url, title, visitCount, lastVisitTime]:rows) {
        BrowserHistory history = {
                .Title = title,
                .Url = url,
                .VisitCount = visitCount,
                .LastVisitTime = TimeEpochFormat(lastVisitTime)
        };
        historyVecData.push_back(history);
    }
}


void historyData::FirefoxParse() {
    auto db = sqlitelib::Sqlite(FirefoxDataFile);
    db.execute(closeJournalMode);
    auto rows = db.execute<sqlite3_int64, string, sqlite_int64, string, int>(queryFirefoxHistory);
    for (const auto &[id, url, visitDate, title, visitCount]:rows) {
        BrowserHistory history = {
                .Title = title,
                .Url = url,
                .VisitCount = visitCount,
                .LastVisitTime = TimeStampFormat(visitDate / 1000000)
        };
        historyVecData.push_back(history);
    }
}

void historyData::OutPut(OutputType format, string browser, string dir) {
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

void historyData::outPutJson(string browser, string dir) {
    string filename = FormatFileName(dir, browser, "history", "json");
    json jsonObject = historyVecData;
    WriteFile(filename, jsonObject.dump(4).c_str());
}

void historyData::outPutCsv(string browser, string dir) {
    //TODO:outPutCsv
}

void historyData::outPutConsole(string browser, string dir) {
    json jsonObject = historyVecData;
    cout << jsonObject.dump(4).c_str() << endl;
}
