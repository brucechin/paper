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

char to_lower(char c)
{
    if ((c >= 'A') && (c <= 'Z'))
        return 'a' + (c - 'A');

    return c;
}

int sgx_is_outside_enclave(void *p, size_t len)
{
    /* dummy implementation to be able to test w/o SGX support */
    return 1;
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
