#include "secret.h"

volatile char c;

void ecall_secret_lookup(char *array, int len)
{
    /* Do the secret lookup */
    c = array[(4096*secret_idx) % len];
}
