//
// Created by Finger on 9/30/2021.
//

#include "parse.h"

void Item::CopyDB() const {
    copyToLocalPath(mainPath, FilePathBase(mainPath));
}


void Item::Release() const {
    remove(FilePathBase(mainPath).c_str());
}