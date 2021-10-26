//
// Created by Finger on 2021/10/25.
//

#ifndef BROWSERPROBE_DECRYPT_H
#define BROWSERPROBE_DECRYPT_H

#include <wincrypt.h>
#include "parse.h"

#define errSecurityKeyIsEmpty "input [security find-generic-password -wa 'Chrome'] in terminal"
#define errPasswordIsEmpty    "password is empty"
#define errDecryptFailed      "decrypt failed, password is empty"
#define errDecodeASN1Failed   "decode ASN1 data failed"
#define errEncryptedLength    "length of encrypted password less than block size"

namespace decrypt {
    uint8_t *DPApi(uint8_t *key);

    uint8_t *ChromePass(uint8_t *key, const uint8_t* encryptPass);

    bool AesGcmDecrypt(_CRYPTOAPI_BLOB cipher, _CRYPTOAPI_BLOB key, _CRYPTOAPI_BLOB iv, _CRYPTOAPI_BLOB *decrypted);
}


#endif //BROWSERPROBE_DECRYPT_H
