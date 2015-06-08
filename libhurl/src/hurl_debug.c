#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void hurl_debug(const char *func,
                const char *msg,
                ...)
{
#ifndef NDEBUG
    char template[1024];
    va_list args;
    snprintf(template,
             sizeof template,
             "[%u] %s(): %s\n",
             (unsigned int )pthread_self(),
             func,
             msg);
    va_start(args, msg);
    vfprintf(stderr, template, args);
    va_end(args);
    fflush(stderr);
#endif
}

char *hurl_allocstrcpy(const char *str,
                       const size_t str_len,
                       const unsigned int alloc_padding)
{
    char *newstr;
    if (str != NULL)
    {
        if ((newstr = calloc(str_len + alloc_padding, sizeof(char))) == NULL)
        {
            exit(EXIT_FAILURE);
        }
        memcpy(newstr, str, str_len);
        return newstr;
    }
    else
    {
        return NULL;
    }
}
