//
// Created by Finger on 8/10/2021.
//

#include "browser_factory.h"

Browser* BrowserFactory::NewChromium(string& profile, string& key, string& name, string& storage) {
    return new Chromium(profile, key, name, storage);
}

Browser* BrowserFactory::NewFirefox(string& profile, string& key, string& name, string& storage) {
    return new Firefox(profile, key, name, storage);
}
