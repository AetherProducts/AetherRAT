#include "certificate.h"
#include "controller.h"
#include "rsa.h"

#define HOST "127.0.0.1"
#define PORT 2003

#define PEM_PRIVATE_CERTIFICATE_SIZE 1704


char pem_private_certificate[PEM_PRIVATE_CERTIFICATE_SIZE] = {
    #include "../../cert/key.in"
};

void
app(void)
{

    // for(int i = 0; i < PEM_PUBLIC_CERTIFICATE_SIZE; i++)
    // {
    //     printf("%c", pem_public_certificate[i]);
    // }

    pcertificate *certificate = NULL;
    pkey_public *key = NULL;
    controller_t *controller = NULL;

    ASSERT(!(certificate = load_certificate(pem_private_certificate, PEM_PRIVATE_CERTIFICATE_SIZE)), "error init certificate")
    ASSERT(!(key = init_key(certificate)),"key public in null")
    ASSERT(!(controller = load_controller(HOST, PORT, key)),"controller is null")

    FLOG("certificate_public %p\n", certificate)
    FLOG("key_public %p\n", key)
    FLOG("controller %p\n", controller)

    start_controller(controller);
}

