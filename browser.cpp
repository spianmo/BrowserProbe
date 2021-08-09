//
// Created by Finger on 8/10/2021.
//

#include "browser.h"
#include "browser_factory.h"

#ifdef _WIN32

string Browser::USERPROFILE = getenv("USERPROFILE");
map<string, BrowserConfig> Browser::browserList = {
        {"firefox",BrowserConfig(USERPROFILE, firefoxName, reinterpret_cast<New>(BrowserFactory::NewFirefox))}
};
#elif _WIN64

#elif __APPLE__ || __MACH__

#elif __linux__

#elif __FreeBSD__

#elif __unix || __unix__

#else

#endif