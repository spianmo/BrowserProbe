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

void copyToLocalPath(const string& src,const string& dst){
    CopyDir copyDir;
    copyDir.copy(src,dst);
}

string filepathBase(const string& filepath){
    int pos = filepath.find_last_of('/') + 1;
    return filepath.substr(pos);
}

string FormatFileName(string dir,string browser,string filename,string format){

}