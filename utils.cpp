//
// Created by Finger on 8/10/2021.
//
#include "utils.h"

string ReadFile(string filename){
    ifstream t("data.txt",ios::in);
    stringstream buffer;
    buffer << t.rdbuf();
    t.close();
    return buffer.str();
}

void WriteFile(string filename,char data[]) {
    ofstream t(filename,ios::out);
    t << data;
    t.close();
}

time_t TimeEpochFormat(int64_t epoch){
    return static_cast<time_t>(epoch);
}