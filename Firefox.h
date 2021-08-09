//
// Created by Finger on 8/6/2021.
//

#ifndef BROWSERPROBE_FIREFOX_H
#define BROWSERPROBE_FIREFOX_H


#include "browser.h"

class Firefox : public Browser{
public:
    string name;
    string profilePath;
    string keyPath;
    string storage;

    Firefox(string profile,string key,string name,string storage);

    void InitSecretKey() override;

    string GetName() override;

    char *GetSecretKey() override;

    vector<Item*> GetAllItems() override;

    Item* GetItem(string itemName) override;

private:
    char secretKey[];
};


#endif //BROWSERPROBE_FIREFOX_H
