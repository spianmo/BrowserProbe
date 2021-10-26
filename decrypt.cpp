//
// Created by Finger on 2021/10/25.
//

#include "decrypt.h"
#include <iostream>
#include <windows.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>


uint8_t *decrypt::DPApi(uint8_t *key) {
    DATA_BLOB dataIn = {strlen(reinterpret_cast<const char *>(key)), key};
    DATA_BLOB dataOut;
    CryptUnprotectData(&dataIn, NULL, NULL, NULL, NULL, 0, &dataOut);
    return dataOut.pbData;
}

uint8_t *decrypt::ChromePass(uint8_t *key, const uint8_t *encryptPass) {
    if (strlen(reinterpret_cast<const char *>(encryptPass)) > 15) {
        // remove Prefix 'v10'
        const DATA_BLOB encryptedPassword = {strlen(reinterpret_cast<const char *>(encryptPass)), encryptPass };
        BYTE decryptedPasswordBuf[512];
        DATA_BLOB decryptedPassword = { 0, decryptedPasswordBuf };
        const DATA_BLOB iv = { 15 - 3, encryptedPassword.pbData + 3 };
        const DATA_BLOB payload = { encryptedPassword.cbData - 15, encryptedPassword.pbData + 15 };

        DATA_BLOB MasterKey = {strlen(reinterpret_cast<const char *>(key)), key};
        AesGcmDecrypt(payload, MasterKey, iv, &decryptedPassword);
        decryptedPassword.cbData -= 16;
        decryptedPassword.pbData[decryptedPassword.cbData] = '\0';
        return decryptedPassword.pbData;
    } else {
        cout << errPasswordIsEmpty << endl;
        return nullptr;
    }
}

bool decrypt::AesGcmDecrypt(DATA_BLOB cipher, DATA_BLOB key, DATA_BLOB iv, PDATA_BLOB decrypted)
{
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx)
        return false;

    if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL))
        return false;

    if (!EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, iv.cbData, NULL))
        return false;

    if (!EVP_DecryptInit_ex(ctx, NULL, NULL, key.pbData, iv.pbData))
        return false;

    int bufLen;
    int sumLen = 0;

    if (!EVP_DecryptUpdate(ctx, decrypted->pbData + sumLen, &bufLen, cipher.pbData + sumLen, cipher.cbData))
        return false;
    sumLen += bufLen;

    int ret = EVP_DecryptFinal_ex(ctx, decrypted->pbData + sumLen, &bufLen);
    sumLen += bufLen;

    EVP_CIPHER_CTX_free(ctx);

    decrypted->cbData = sumLen;

    //return ret > 0;
    return true;
}