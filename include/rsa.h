#ifndef RSA_H
#define RSA_H

#include "log.h"


#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/decoder.h>
#include <openssl/core_names.h>

typedef EVP_PKEY* pkey_public;
typedef EVP_PKEY* pkey_private;


pkey_private init_key (void *certificate);

void decrypt (const char *in_str, size_t in_len, char *out_buffer, size_t *out_len, EVP_PKEY_CTX *ctx);
void encrypt (const char *in_str, size_t in_len, char *out_buffer, size_t *out_len, EVP_PKEY_CTX *ctx);

#endif