#include <arpa/inet.h>
#include <memory.h>

#include "controller.h"
#include "rsa.h"

#define PAGE_SIZE 4096

static int client_socket;
static struct sockaddr_in address;
void 
start_controller (controller_t *controller)
{
    ASSERT(!controller, "controller is null")   
#ifdef WIN32 
    // init winsocket pram
#endif
    ASSERT((client_socket = socket (AF_INET,SOCK_STREAM,0), client_socket < 0), "error init socket")
    address.sin_family = AF_INET;
    address.sin_port = htons(controller->port);
    address.sin_addr.s_addr = inet_addr(controller->host);

    ASSERT((connect(client_socket, (struct sockaddr*)&address, sizeof(address))) < 0, "error connect to host")
    while(1)
    {   
        char *message = malloc(PAGE_SIZE);
        size_t message_size = NULL;
        char *buffer = malloc(PAGE_SIZE);
        if(!buffer)
            continue;
        memset(buffer, '\0', PAGE_SIZE);
        memset(message, '\0', PAGE_SIZE);
        
recv:
        size_t len = recv (client_socket, buffer, PAGE_SIZE, 0);
        if(!len)
            goto recv;
        // decrypt
        //  thread

        decrypt(buffer,len, message, &message_size, controller->openssl.ctx);
        
        FLOG("input len %d\n", len)
        FLOG("message len %d\n", message_size)
        // for(int i =0; i < message_size; i++)
        // {
        //     printf("%c\n", message[i]);
        // }

        free(buffer); 
    }
}


controller_t* 
load_controller (const char* host, uint16_t port, void* public_key)
{
    controller_t* controll = NULL;
    ASSERT((!host || !port || !public_key), "host or port or public_key is null\n")
    ASSERT(!(controll = malloc(sizeof(controller_t))), "controll is null\n")
    
    OSSL_LIB_CTX *libctx = NULL;
    const char *propquery = NULL;

    controll->host = host;
    controll->port = port;
    controll->openssl.ctx = EVP_PKEY_CTX_new_from_pkey(libctx, (EVP_PKEY*)public_key, propquery);
    ASSERT(!controll->openssl.ctx, "context is null\n")
    
    return controll;
}
