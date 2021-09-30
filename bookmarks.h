//
// Created by Finger on 8/6/2021.
//

#ifndef BROWSERPROBE_BOOKMARKS_H
#define BROWSERPROBE_BOOKMARKS_H

#include <cstdio>
#include <iostream>
#include "parse.h"
#include <vector>
#include "sqlitelib.h"
#include "json.hpp"

using namespace std;
using namespace nlohmann;

typedef struct Bookmark {
    int64_t ID{};
    string Name;
    string Type;
    string URL;
    time_t DateAdded{};
} BrowserBookMark;

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(BrowserBookMark, ID, Name, Type, URL, DateAdded)

typedef std::vector<BrowserBookMark> BookmarkVec;

class bookmarks : public Item {
public:
    BookmarkVec bookmarksData;

    bookmarks(string main, string sub);

    void ChromeParse(bytes secretKey) override;

    void FirefoxParse() override;

    void OutPut(OutputType format, string browser, string dir) override;

private:
    void getBookmarkChildren(json node);

    void outPutJson(string browser, string dir) override;

    void outPutCsv(string browser, string dir) override;

    void outPutConsole(string browser, string dir) override;
};


#endif //BROWSERPROBE_BOOKMARKS_H
