//
// Created by Finger on 9/30/2021.
//

#ifndef BROWSERPROBE_CREDITCARDS_H
#define BROWSERPROBE_CREDITCARDS_H

#include <cstdio>
#include <iostream>
#include "parse.h"
#include <vector>
#include "sqlitelib.h"
#include "json.hpp"

using namespace std;
using namespace nlohmann;

typedef struct card {
    string GUID;
    string Name;
    string ExpirationYear;
    string ExpirationMonth;
    string CardNumber;
} BrowserCard;

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(BrowserCard, GUID, Name, ExpirationYear, ExpirationMonth, CardNumber)

typedef std::map<string, std::vector<BrowserCard>> CardMap;

class creditCards : public Item {
public:
    CardMap cardData;

    creditCards(string main, string sub);

    void ChromeParse(uint8_t* secretKey) override;

    void FirefoxParse() override;

    void OutPut(OutputType format, string browser, string dir) override;

private:

    void outPutJson(string browser, string dir) override;

    void outPutCsv(string browser, string dir) override;

    void outPutConsole(string browser, string dir) override;
};


#endif //BROWSERPROBE_CREDITCARDS_H
