//
// Created by Finger on 8/6/2021.
//

#include "Chromium.h"
#include "bookmarks.h"

Chromium::Chromium(string profile, string key, string name, string storage) {
    this->profilePath = std::move(profile);
    this->keyPath = std::move(key);
    this->name = std::move(name);
    this->storage = std::move(storage);
}

void Chromium::InitSecretKey() {

}

string Chromium::GetName() {
    return this->name;
}

char *Chromium::GetSecretKey() {
    return this->secretKey;
}

vector<Item*> Chromium::GetAllItems() {
    return (vector<Item*>) 11;
}

Item* Chromium::GetItem(string itemName) {
    auto book1 = new bookmarks("", "");
    return book1;
}