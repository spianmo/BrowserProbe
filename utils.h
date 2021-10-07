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

string BookMarkType(int64_t type);
time_t TimeStampFormat(int64_t stamp);
time_t TimeEpochFormat(int64_t epoch);
string TimeFormat(time_t tmt);
void copyToLocalPath(const string& src,const string& dst);
string FilePathBase(const string& filepath);
string FormatFileName(const string &dir, const string &browser, const string &filename, const string &format);
bool IntToBool(int i);

#endif //BROWSERPROBE_UTILS_H