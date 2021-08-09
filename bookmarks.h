//
// Created by Finger on 8/6/2021.
//

#ifndef BROWSERPROBE_BOOKMARKS_H
#define BROWSERPROBE_BOOKMARKS_H


#include "cJSON.h"
#include "parse.h"
#include <vector>

using namespace std;

typedef struct Bookmark{
    int64_t   ID{};
    string    Name;
    string    Type;
    string    URL;
    time_t    DateAdded{};
} BrowserBookMark;

typedef std::vector<BrowserBookMark*> BookmarkPtrVec;

class bookmarks : public Item {
public:
    string mainPath;
    BookmarkPtrVec bookmarksData;
    bookmarks(string main, string sub);
    void ChromeParse(char key[]) override;

    void FirefoxParse() override;

    void OutPut(string format, string browser, string dir) override;

    void CopyDB() override;

    void Release() override;

private:
    cJSON* getBookmarkChildren(cJSON* node);
};


#endif //BROWSERPROBE_BOOKMARKS_H
