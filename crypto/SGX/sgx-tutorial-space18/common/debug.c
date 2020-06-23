#include "debug.h"

int enclave_rv = 0;

void dump_hex(char *str, uint8_t *buf, int len)
{
    printf("%s = ", str);
    for (int i=0; i < len; i++)
        printf("%02x ", *(buf + i));
    printf("\n");
}

