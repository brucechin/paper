#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <cacheutils.h>
#include "secret.h"

#define NUM_SAMPLES     100000
#define DELAY           1

uint64_t diff[NUM_SAMPLES];
int user_len, secret_len;

char *read_from_user(void)
{
    char *buffer = NULL;
    int len; size_t size;

    printf("Enter super secret password ('q' to exit): ");
    if ((len=getline(&buffer, &size, stdin)) != -1)
    {
        /* get rid of the terminating newline character */
        buffer[len-1]='\0';
        printf("--> You entered: '%s'\n", buffer);
        return buffer;
    }
    else
    {
        printf("--> failure to read line\n");
        return NULL;
    }
}

void delay(void)
{
    volatile int i;
    for (i=0; i<100;i++);
}

int check_pwd(char *user)
{
    int i;

    /* reject if incorrect length */
    if (user_len != secret_len)
        return 0;

    #if DELAY
        delay();
    #endif
    
    /* reject on first byte mismatch */
    for (i=0; i < user_len; i++)
    {
        if (user[i] != SECRET_PWD[i])
            return 0;

        #if DELAY
            delay();
        #endif
    }

    /* user password passed all the tests */
    return 1;
}

int compare(const void * a, const void * b) {
   return ( *(uint64_t*)a - *(uint64_t*)b );
}

int main()
{
    char *pwd;
    int j, allowed = 0;
    uint64_t tsc1, tsc2, med;

    while ((pwd = read_from_user()) && strcmp(pwd, "q"))
    {

    user_len = strlen(pwd);
    secret_len = strlen(SECRET_PWD);

    /* collect execution timing samples */
    for (j=0; j < NUM_SAMPLES; j++)
    {
        tsc1 = rdtsc_begin();
        allowed = check_pwd(pwd);
        tsc2 = rdtsc_end();
        diff[j] = tsc2 - tsc1;
    }

    if (allowed)
    {
        printf(" _______________\n");
        printf("< ACCESS ALLOWED >\n");
        printf(" ---------------\n");
        printf("        \\\n");
        printf("         \\\n");
        printf("        .--. \n");
        printf("       |o_o | \n");
        printf("       |:_/ | \n");
        printf("      //   \\ \\ \n");
        printf("     (|     | ) \n");
        printf("    /'\\_   _/`\\ \n");
        printf("    \\___)=(___/ \n\n");
    }
    else
    {
        printf(" _______________\n");
        printf("< ACCESS DENIED >\n");
        printf(" ---------------\n");
        printf("        \\\n");
        printf("         \\\n");
        printf("    \\|/ ____ \\|/  \n");
        printf("    \"@'/ .. \\`@\" \n");
        printf("    /_| \\__/ |_\\  \n");
        printf("       \\__U_/      \n\n");
    }
    
    /* compute median over all samples (avg may be affected by outliers) */
    qsort(diff, NUM_SAMPLES, sizeof(uint64_t), compare);
    med = diff[NUM_SAMPLES/2];
    printf("time (med clock cycles): %lu\n", med);

    free(pwd);

    }
    return 0;
}
