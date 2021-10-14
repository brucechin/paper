#include "encl_t.h"
#include <sgx_trts.h>
#include "secret.h"

volatile char c;

void ecall_secret_lookup(char *array, int len)
{
    /* First ensure the _untrusted_ pointer points outside the enclave */
    if (!sgx_is_outside_enclave(array, len))
        return;

    /* Now do the secret lookup */
    c = array[(4096*secret_idx) % len];
}

