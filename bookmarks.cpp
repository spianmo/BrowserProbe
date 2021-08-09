//
// Created by Finger on 8/6/2021.
//

#include <iostream>
#include "bookmarks.h"

bookmarks::bookmarks(string main, string sub) {
    this->mainPath = std::move(main);
}

void bookmarks::ChromeParse(char key[]) {
    string bookmarks = ReadFile(ChromeBookmarkFile);
    cJSON *root = cJSON_Parse(bookmarks.c_str());
    cJSON *arrayobj = cJSON_GetObjectItem(root, "roots");
    int size = cJSON_GetArraySize(arrayobj);
    cJSON *item;
    for (int i = 0; i < size; i++) {
        item = cJSON_GetArrayItem(arrayobj, i);
        getBookmarkChildren(item);
    }
}

cJSON *bookmarks::getBookmarkChildren(cJSON *node) {
    Bookmark bm;
    bm.ID = cJSON_GetObjectItem(node, bookmarkID)->valueint;
    bm.Name = cJSON_GetObjectItem(node, bookmarkName)->valuestring;
    bm.URL = cJSON_GetObjectItem(node, bookmarkUrl)->valuestring;
    bm.DateAdded = TimeEpochFormat(cJSON_GetObjectItem(node, bookmarkID)->valueint);
    cJSON *nodeType = cJSON_GetObjectItem(node, bookmarkType);
    cJSON *children = cJSON_GetObjectItem(node, bookmarkChildren);
    if (nodeType != nullptr) {
        bm.Type = nodeType->valuestring;
        bookmarksData.push_back(&bm);
        if (children != nullptr && cJSON_IsArray(children)) {
            int size = cJSON_GetArraySize(children);
            cJSON *item;
            for (int i = 0; i < size; i++) {
                item = cJSON_GetArrayItem(children, i);
                children = getBookmarkChildren(item);
            }
        }
    }
    return children;
}

void bookmarks::FirefoxParse() {
    cout << "BMW" << endl;
}

void bookmarks::OutPut(string format, string browser, string dir) {
    cout << "BMW" << endl;
}

void bookmarks::CopyDB() {
    cout << "BMW" << endl;
}

void bookmarks::Release() {
    cout << "BMW" << endl;
}
