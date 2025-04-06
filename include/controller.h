#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <stdint.h>
#include <openssl/evp.h>

#include "log.h"


typedef struct
{
    const char *host;
    uint16_t port;

    struct {
        EVP_PKEY_CTX *ctx;
    } openssl;
} controller_t;

controller_t *load_controller (const char* host, uint16_t port, void* public_key);
void start_controller (controller_t *controller);
#endif 