cmake_minimum_required(VERSION 3.19)
project(BrowserProbe)

set(CMAKE_CXX_STANDARD 23)

set(VENDOR ${CMAKE_SOURCE_DIR}/vendor)

add_library(sqlite3
        STATIC
        ${VENDOR}/sqlite3/sqlite3.c
        )
include_directories(sqlite3 ${VENDOR}/sqlite3/)

add_library(openssl STATIC IMPORTED)
include_directories(openssl ${VENDOR}/openssl/include)
set_target_properties(openssl PROPERTIES IMPORTED_LOCATION ${VENDOR}/openssl/lib)

add_executable(BrowserProbe main.cpp browser.h parse.h utils.h bookmarks.cpp bookmarks.h Chromium.cpp Chromium.h Firefox.cpp Firefox.h browser.cpp browser_factory.cpp browser_factory.h utils.cpp sqlitelib.h copy_dir.cpp copy_dir.h json.hpp stringutil.h parse.cpp cookies.cpp cookies.h historyData.cpp historyData.h downloads.cpp downloads.h passwords.cpp passwords.h creditCards.cpp creditCards.h base64.h decrypt.cpp decrypt.h)


target_link_libraries(BrowserProbe
        openssl
        sqlite3)