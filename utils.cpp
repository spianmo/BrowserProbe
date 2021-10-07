//
// Created by Finger on 8/10/2021.
//
#include "utils.h"

string BookMarkType(int64_t type) {
    return type == 1 ? "url" : "folder";
}

time_t TimeStampFormat(int64_t stamp) {
    return static_cast<time_t>(stamp >= 99999999999ll ? stamp / 1000 : stamp);

}

time_t TimeEpochFormat(int64_t epoch) {
    long long epoch_start = 11644473600000ll;
    return static_cast<time_t>((epoch / 1000 - epoch_start) / 1000);
}

string TimeFormat(time_t tmt)
{
    char str[100];
    tm time{};
    localtime_s(&time, &tmt);
    strftime(str, sizeof(str), "%Y-%m-%d %H:%M:%S", &time);
    return str;
}

void copyToLocalPath(const string &src, const string &dst) {
    CopyDir copyDir;
    copyDir.copy(src, dst);
}

string FilePathBase(const string &filename) {
#ifdef __linux__
    const string slash = "/";
#elif _WIN32
    const string slash = "\\";
#endif
    size_t lastSlashPosition = filename.find_last_of(slash);

    if (lastSlashPosition != string::npos)
        return filename.substr(lastSlashPosition + 1);
    else
        return "";
}

string FormatFileName(const string &dir, const string &browser, const string &filename, const string &format) {
    string r = ReplaceAll(Trim(ToLower(browser)), " ", "_");
    string p = dir + Format("%s_%s.%s", r.c_str(), filename.c_str(), format.c_str());
    return p;
}

bool IntToBool(int i) {
    return i == 1;
}
