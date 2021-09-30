//
// Created by Finger on 8/10/2021.
//
#include "utils.h"

string ReadFile(string filename) {
    ifstream t(filename, ios::in);
    stringstream buffer;
    buffer << t.rdbuf();
    t.close();
    return buffer.str();
}

void WriteFile(string filename, const char data[]) {
    ofstream t(filename, ios::out);
    t << data;
    t.close();
}

string BookMarkType(int64_t type) {
    return type == 1 ? "url" : "folder";
}

time_t TimeStampFormat(int64_t stamp) {
    return static_cast<time_t>(stamp);

}

time_t TimeEpochFormat(int64_t epoch) {
    return static_cast<time_t>(epoch);
}

void copyToLocalPath(const string &src, const string &dst) {
    CopyDir copyDir;
    copyDir.copy(src, dst);
}

string FilePathBase(const string &filename)
{
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
