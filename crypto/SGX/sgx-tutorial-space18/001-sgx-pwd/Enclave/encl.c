#include "encl_t.h"
#include "secret.h"
#include <string.h>

/*
 * NOTE: for demonstration purposes, we hard-code secrets at compile time and
 * abstract away how they are securely provisioned at runtime.
 */
int super_secret_constant   = 0xdeadbeef;

int ecall_dummy(int i)
{
    return super_secret_constant + i;
}

void delay(void)
{
    volatile int i;
    for (i=0; i<10000;i++);
}

int check_pwd(char *user)
{
    int i;
    int user_len = strlen(user);

    /* reject if incorrect length */
    if (user_len != SECRET_LEN)
        return 0;

    #if DELAY
        delay();
    #endif
    
    /* reject on first byte mismatch */
    for (i=0; i < user_len; i++)
    {
        if (user[i] != SECRET_PIN[i])
            return 0;

        #if DELAY
            delay();
        #endif
    }

    /* user password passed all the tests */
    return 1;
}

/* =========================== START SOLUTION =========================== */
/* ============================ END SOLUTION ============================ */
