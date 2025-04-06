#include "certificate.h"


pcertificate*
load_certificate (const void *buffer, size_t len)
{
    FILE *object =  NULL;
    ASSERT(!buffer || !len, "buffer or len is null")
    ASSERT(!(object = tmpfile()),"error init object")
    ASSERT((fwrite(buffer, sizeof( char), len, object)) < 0,"error fwrite in buffer")

    rewind(object);
    
    return object;
}