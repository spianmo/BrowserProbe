//
// Created by Finger on 8/6/2021.
//

#ifndef BROWSERPROBE_UTILS_H
#define BROWSERPROBE_UTILS_H

#include <string>
#include <fstream>
#include <sstream>
#include "copy_dir.h"

using namespace std;

string ReadFile(string filename);
void WriteFile(string filename,const char data[]);
string BookMarkType(int64_t type);
time_t TimeStampFormat(int64_t stamp);
time_t TimeEpochFormat(int64_t epoch);
void copyToLocalPath(const string& src,const string& dst);
string filepathBase(const string& filepath);
string FormatFileName(string dir,string browser,string filename,string format);

#endif //BROWSERPROBE_UTILS_H