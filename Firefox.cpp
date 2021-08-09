//
// Created by Finger on 8/6/2021.
//

#include "Firefox.h"

Firefox::Firefox(string profile, string key, string name, string storage) {
    this->profilePath = std::move(profile);
    this->keyPath = std::move(key);
    this->name = std::move(name);
    this->storage = std::move(storage);
}

void Firefox::InitSecretKey() {

}

string Firefox::GetName() {
    return this->name;
}

char *Firefox::GetSecretKey() {
    return this->secretKey;
}

vector<Item*> Firefox::GetAllItems() {
    return (std::vector<Item*>) 11;
}

Item* Firefox::GetItem(string itemName) {
    return nullptr;
}