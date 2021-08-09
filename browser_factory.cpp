//
// Created by Finger on 8/10/2021.
//

#include "browser_factory.h"

Chromium BrowserFactory::NewChromium(string& profile, string& key, string& name, string& storage) {
    return {profile, key, name, storage};
}

Firefox BrowserFactory::NewFirefox(string& profile, string& key, string& name, string& storage) {
    return {profile, key, name, storage};
}
