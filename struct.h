//
// Created by Finger on 8/4/2021.
//

#ifndef BROWSERPROBE_STRUCT_H
#define BROWSERPROBE_STRUCT_H

#include <string>
using namespace std;

struct loginData {
    string      UserName;
    char*      encryptPass;
    char*      encryptUser;
    string      Password;
    string      LoginUrl;
    time_t      CreateDate;
};


struct history{
    string        Title;
    string        Url;
    int           VisitCount;
    time_t        LastVisitTime;
};
struct download{
    string     TargetPath;
    string     Url;
    int64_t    TotalBytes;
    time_t     StartTime;
    time_t     EndTime;
    string     MimeType;
};
struct card{
    string          GUID;
    string          Name;
    string          ExpirationYear;
    string          ExpirationMonth;
    string          CardNumber;
};

#endif //BROWSERPROBE_STRUCT_H
