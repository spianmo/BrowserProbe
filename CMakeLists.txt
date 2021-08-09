cmake_minimum_required(VERSION 3.19)
project(BrowserProbe)

set(CMAKE_CXX_STANDARD 14)

add_executable(BrowserProbe main.cpp cJSON.cpp cJSON.h struct.h browser.h parse.h utils.h bookmarks.cpp bookmarks.h Chromium.cpp Chromium.h Firefox.cpp Firefox.h browser.cpp browser_factory.cpp browser_factory.h utils.cpp)