//
// Created by Finger on 8/6/2021.
//

#ifndef BROWSERPROBE_CHROMIUM_H
#define BROWSERPROBE_CHROMIUM_H
#include "browser.h"
#include <utility>
#include <vector>

using namespace std;

class Chromium :public Browser{
public:
    string name;
    string profilePath;
    string keyPath;
    string storage;

    Chromium(string profile,string key,string name,string storage);

    void InitSecretKey() override;

    string GetName() override;

    char *GetSecretKey() override;

    vector<Item*> GetAllItems() override;

    Item* GetItem(string itemName) override;

private:
    char secretKey[];

};


#endif //BROWSERPROBE_CHROMIUM_H
