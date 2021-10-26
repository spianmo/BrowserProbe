//
// Created by Finger on 9/30/2021.
//

#include "downloads.h"

downloads::downloads(string main, string sub) {
    this->mainPath = std::move(main);
}

void downloads::ChromeParse(uint8_t* secretKey) {
    auto db = sqlitelib::Sqlite(ChromeDownloadFile);
    auto rows = db.execute<string, string, sqlite_int64, sqlite_int64, sqlite_int64, string>(
            queryChromiumDownload);
    for (const auto &[targetPath, tabUrl, totalBytes, startTime, endTime, mimeType]:rows) {
        BrowserDownload download = {
                .TargetPath = targetPath,
                .Url = tabUrl,
                .TotalBytes = totalBytes,
                .StartTime = TimeEpochFormat(startTime),
                .EndTime = TimeEpochFormat(endTime),
                .MimeType = mimeType
        };
        downloadData.push_back(download);
    }
}


void downloads::FirefoxParse() {
    auto db = sqlitelib::Sqlite(FirefoxDataFile);
    db.execute(closeJournalMode);
    auto rows = db.execute<sqlite3_int64, string, string, sqlite_int64>(queryFirefoxDownload);
    for (const auto &[placeID, content, url, dateAdded]:rows) {
        vector<string> contentList = Split(content, ",{");
        if (contentList.size() > 1){
            string path = contentList[0];
            json jsonObj = json::parse("{" + contentList[1]);
            time_t endTime = TimeEpochFormat(jsonObj["endTime"].get<int64_t>());
            int64_t fileSize = jsonObj["fileSize"].get<int64_t>();
            BrowserDownload download = {
                    .TargetPath = path,
                    .Url = url,
                    .TotalBytes = fileSize,
                    .StartTime = TimeStampFormat(dateAdded / 1000000),
                    .EndTime = TimeStampFormat(endTime / 1000)
            };
            downloadData.push_back(download);
        }
    }
}

void downloads::OutPut(OutputType format, string browser, string dir) {
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

void downloads::outPutJson(string browser, string dir) {
    string filename = FormatFileName(dir, browser, "download", "json");
    json jsonObject = downloadData;
    WriteFile(filename, jsonObject.dump(4).c_str());
}

void downloads::outPutCsv(string browser, string dir) {
    //TODO:outPutCsv
}

void downloads::outPutConsole(string browser, string dir) {
    json jsonObject = downloadData;
    cout << jsonObject.dump(4).c_str() << endl;
}
