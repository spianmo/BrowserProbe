//
// Created by Finger on 9/30/2021.
//

#include "creditCards.h"

creditCards::creditCards(string main, string sub) {
    this->mainPath = std::move(main);
}

void creditCards::ChromeParse(bytes secretKey) {
    auto db = sqlitelib::Sqlite(ChromeCreditFile);
    auto rows = db.execute<string, string, string, string, bytes>(
            queryChromiumCredit);
    for (const auto &[guid, name, month, year, encryptValue]:rows) {
        BrowserCard card = {
                .GUID = guid,
                .Name = name,
                .ExpirationYear = year,
                .ExpirationMonth = month
        };

        if (secretKey == nullptr) {
            //TODO: card.CardNumber = decrypt::DPApi(encryptValue);
        } else {
            //TODO: card.CardNumber = decrypt::ChromePass(secretKey, encryptValue);
        }

        vector<BrowserCard> vector_card;
        if (cardData.contains(guid)) {
            vector_card = cardData.at(guid);
            vector_card.push_back(card);
        } else {
            cardData.insert(pair<string, vector<BrowserCard>>(guid, vector_card));
        }
    }
}

void creditCards::FirefoxParse() {
    return;
}

void creditCards::OutPut(OutputType format, string browser, string dir) {
    switch (format) {
        case JSON:
            outPutJson(browser, dir);
            break;
        case CSV:
            outPutCsv(browser, dir);
            break;
        case CONSOLE:
            outPutConsole(browser, dir);
            break;
    }
}

void creditCards::outPutJson(string browser, string dir) {
    string filename = FormatFileName(dir, browser, "credit", "json");
    json jsonObject = cardData;
    WriteFile(filename, jsonObject.dump(4).c_str());
}

void creditCards::outPutCsv(string browser, string dir) {
    //TODO:outPutCsv
}

void creditCards::outPutConsole(string browser, string dir) {
    json jsonObject = cardData;
    cout << jsonObject.dump(4).c_str() << endl;
}

