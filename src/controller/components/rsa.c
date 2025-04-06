#include "rsa.h"


pkey_private
init_key (void *certificate)
{
    ASSERT(!certificate,"certificate is null")
    
    return PEM_read_PrivateKey((FILE*)certificate, NULL, NULL, NULL);
}


void 
decrypt (const char *in_str, size_t in_len, char *out_buffer, size_t *out_len, EVP_PKEY_CTX *ctx)
{
    //ASSERT((!in_str || !in_len || !out_buffer || !out_len || !ctx), "error param")
    ASSERT(EVP_PKEY_decrypt_init(ctx) <= 0, "error EVP_PKEY_decrypt_init")
    ASSERT(EVP_PKEY_decrypt(ctx, NULL, out_len, in_str, in_len) <= 0, "error EVP_PKEY_decrypt")
    ASSERT(EVP_PKEY_decrypt(ctx, out_buffer, out_len, in_str, in_len) <= 0, "error EVP_PKEY_decrypt")
 
    // EVP_PKEY_decrypt_init(ctx);
    // //FLOG(EVP_PKEY_decrypt(ctx, NULL, out_len, in_str, in_len), "error EVP_PKEY_decrypt")
    // FLOG(EVP_PKEY_decrypt(ctx, out_buffer, out_len, in_str, in_len), "error EVP_PKEY_decrypt")
}

void 
encrypt (const char *in_str, size_t in_len, char *out_buffer, size_t *out_len, EVP_PKEY_CTX *ctx)
{
    ASSERT((!in_str || !in_len || !out_buffer || !out_len || !ctx), "error param")
    ASSERT((!EVP_PKEY_encrypt_init(ctx)), "error EVP_PKEY_decrypt_init")
    ASSERT((!EVP_PKEY_encrypt(ctx, out_buffer, out_len, in_str, in_len)), "error EVP_PKEY_decrypt")
}

