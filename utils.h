//
// Created by Finger on 8/6/2021.
//

#ifndef BROWSERPROBE_UTILS_H
#define BROWSERPROBE_UTILS_H

#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string ReadFile(string filename);
void WriteFile(string filename,char data[]);
time_t TimeEpochFormat(int64_t epoch);

#endif //BROWSERPROBE_UTILS_H