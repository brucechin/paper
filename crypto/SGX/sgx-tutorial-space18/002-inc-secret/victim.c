#include "victim.h"

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
