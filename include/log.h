#ifndef LOG
#define LOG

#define DEBUG

#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG
# define ASSERT(x, fmt, ...) \
    if(x) { \
        fprintf (stderr, "%s:%s():%d: ",              \
                                            __FILE__, __func__, __LINE__);       \
        fprintf (stderr, fmt, ##__VA_ARGS__);    \
        exit(0); \
    } 
# define FLOG(fmt,...) \
    {                                               \
        fprintf (stderr, "%s:%s():%d: ",              \
                                            __FILE__, __func__, __LINE__);       \
        fprintf (stderr, fmt, ##__VA_ARGS__);         \
    }
#else
# define ASSERT(x,msg) \
    if(x) { \
        exit(0); \
    } 
# define LOG(fmt, ...)
#endif



#endif