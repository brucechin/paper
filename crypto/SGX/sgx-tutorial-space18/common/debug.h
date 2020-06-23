#ifndef DEBUG_H_INC
#define DEBUG_H_INC

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ASSERT(cond)                                                    \
    do {                                                                \
        if (!(cond))                                                    \
        {                                                               \
            perror("[" __FILE__ "] assertion '" #cond "' failed");      \
            abort();                                                    \
        }                                                               \
    } while(0)

#define SGX_ASSERT(f)  { if ( SGX_SUCCESS != (enclave_rv = (f)) )       \
 {                                                                      \
       printf( "Error calling enclave at %s:%d (rv=0x%x)\n", __FILE__,  \
                                              __LINE__, enclave_rv);    \
        abort();                                                        \
 } }

#define info(msg, ...)                                                  \
    do {                                                                \
        printf("[" __FILE__ "] " msg "\n", ##__VA_ARGS__);              \
        fflush(stdout);                                                 \
    } while(0)

#define info_event(msg, ...)                                                                        \
do {                                                                                                \
    printf("\n--------------------------------------------------------------------------------\n"); \
    info(msg,##__VA_ARGS__);                                                                        \
    printf("--------------------------------------------------------------------------------\n\n"); \
} while(0)

extern int enclave_rv;

void dump_hex(char *str, uint8_t *buf, int len);

#endif
