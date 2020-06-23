#include "encl_t.h"
#include <sgx_trts.h>

/* see asm.S */
extern int a;

void ecall_inc_secret(int s)
{
    if (s)
        a += 1;
}

void ecall_inc_secret_maccess(int s)
{
    if (s)
        a += 1;

    /* DEFENSE IDEA: let's always access 'a', independent of the secret */
    volatile int b = a;
}

void *ecall_get_a_adrs(void)
{
    return (void*) &a;
}
