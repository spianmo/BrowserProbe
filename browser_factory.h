//
// Created by Finger on 8/10/2021.
//

#ifndef BROWSERPROBE_BROWSER_FACTORY_H
#define BROWSERPROBE_BROWSER_FACTORY_H


#include "Chromium.h"
#include "Firefox.h"

class BrowserFactory {
public:
    static Browser* NewChromium(string& profile,string& key,string& name,string& storage);
    static Browser* NewFirefox(string& profile,string& key,string& name,string& storage);
};


#endif //BROWSERPROBE_BROWSER_FACTORY_H
