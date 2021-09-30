//
// Created by Finger on 8/6/2021.
//

#ifndef BROWSERPROBE_UTILS_H
#define BROWSERPROBE_UTILS_H

#include <string>
#include <fstream>
#include <sstream>
#include "copy_dir.h"
#include "stringutil.h"

using namespace std;

string ReadFile(string filename);
void WriteFile(string filename,const char data[]);
string BookMarkType(int64_t type);
time_t TimeStampFormat(int64_t stamp);
time_t TimeEpochFormat(int64_t epoch);
void copyToLocalPath(const string& src,const string& dst);
string FilePathBase(const string& filepath);
string FormatFileName(const string &dir, const string &browser, const string &filename, const string &format);

#endif //BROWSERPROBE_UTILS_H