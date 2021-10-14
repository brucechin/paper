#include "encl_t.h"
#include <sgx_trts.h>
#include <string.h>

#define ARRAY_LEN       0x2000
char __attribute__((aligned(0x1000))) array[ARRAY_LEN];
char *secret_pt = &array[(ARRAY_LEN/2)-1];

void ecall_set_secret(char b)
{
    int i;

    for (i=0; i < ARRAY_LEN; i++)
        array[i] = 0x00;

    *secret_pt = b;
}

void *ecall_get_secret_adrs(void)
{
    return secret_pt;
}

char to_lower(char c)
{
    if ((c >= 'A') && (c <= 'Z'))
        return 'a' + (c - 'A');

    return c;
}

void ecall_to_lowercase(char *s)
{
    int i; char c;

    /* First ensure the _untrusted_ string lies outside the enclave */
    if (!sgx_is_outside_enclave(s, strlen(s)))
        return;

    /* Now transform the string character per character */
    for (i=0; i < strlen(s); i++)
        s[i] = to_lower(s[i]);
}
