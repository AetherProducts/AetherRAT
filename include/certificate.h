#ifndef CERTIFICATE_H
#define CERTIFICATE_H
#include <stdio.h>
#include "log.h"

typedef FILE *pcertificate;

pcertificate *load_certificate (const void *buffer, size_t len);

#endif