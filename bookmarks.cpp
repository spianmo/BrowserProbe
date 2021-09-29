//
// Created by Finger on 8/6/2021.
//

#include "bookmarks.h"

bookmarks::bookmarks(string main, string sub) {
    this->mainPath = std::move(main);
}

void bookmarks::ChromeParse(char key[]) {
    string bookmarks = ReadFile(ChromeBookmarkFile);
    json root = json::parse(bookmarks);
    array arrayObj = root["roots"];
    for (auto& element : arrayObj) {
        getBookmarkChildren(element);
    }
}

void bookmarks::getBookmarkChildren(json j) {
    Bookmark bm {
        .ID = j[bookmarkID].get<int64_t>(),
        .Name = j[bookmarkName].get<string>(),
        .URL = j[bookmarkUrl].get<string>(),
        .DateAdded = j[bookmarkAdded].get<time_t>()
    };
    json childArray = j[bookmarkChildren];
    if (!j[bookmarkType].is_null()){
        bm.Type = j[bookmarkType].get<string>();
        bookmarksData.push_back(bm);
        if (!childArray.is_null() && childArray.is_array()){
            for (auto& child : childArray){
                getBookmarkChildren(child);
            }
        }
    }
}

void bookmarks::FirefoxParse() {
    auto db = sqlitelib::Sqlite(FirefoxDataFile);
    db.execute(closeJournalMode);
    auto bookmarkRows = db.execute<sqlite3_int64, string, sqlite3_int64, sqlite3_int64, string>(queryFirefoxBookMarks);
    for (const auto &[id, url, bType, dateAdded, title]:bookmarkRows) {
        Bookmark bookmark = {id, title, BookMarkType(bType), url, dateAdded / 1000000};
        bookmarksData.push_back(bookmark);
    }
}

void bookmarks::OutPut(OutputType format, string browser, string dir) {
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

void bookmarks::outPutJson(string browser, string dir) {
    json jsonObject = bookmarksData;
    WriteFile("bookmark.json", jsonObject.dump(4).c_str());
}

void bookmarks::outPutCsv(string browser, string dir) {
    //TODO:outPutCsv
}

void bookmarks::outPutConsole(string browser, string dir) {
    json jsonObject = bookmarksData;
    cout << jsonObject.dump(4).c_str() << endl;
}

