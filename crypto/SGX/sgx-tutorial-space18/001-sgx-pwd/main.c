/* utility headers */
#include "debug.h"
#include <cacheutils.h>

/* SGX untrusted runtime */
#include <sgx_urts.h>
#include "Enclave/encl_u.h"

#define NUM_SAMPLES     1000
#define DELAY           1

uint64_t diff[NUM_SAMPLES];

/* define untrusted OCALL functions here */

void ocall_print(const char *str)
{
    info("ocall_print: enclave says: '%s'", str);
}

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

sgx_enclave_id_t create_enclave(void)
{
    sgx_launch_token_t token = {0};
    int updated = 0;
    sgx_enclave_id_t eid = -1;

    info_event("Creating enclave...");
    SGX_ASSERT( sgx_create_enclave( "./Enclave/encl.so", /*debug=*/1,
                                    &token, &updated, &eid, NULL ) );

    return eid;
}

int compare(const void * a, const void * b) {
   return ( *(uint64_t*)a - *(uint64_t*)b );
}

int main( int argc, char **argv )
{
    sgx_enclave_id_t eid = create_enclave();
    int rv = 1, secret = 0;
    char *pwd;
    int j, tsc1, tsc2, med, allowed = 0;

    /* Example SGX enclave ecall invocation */
    SGX_ASSERT( ecall_dummy(eid, &rv, 1) );
    
    /* ---------------------------------------------------------------------- */
    while ((pwd = read_from_user()) && strcmp(pwd, "q"))
    {

    /* collect execution timing samples */
    for (j=0; j < NUM_SAMPLES; j++)
    {
        tsc1 = rdtsc_begin();
        /* =========================== START SOLUTION =========================== */
        /* ============================ END SOLUTION ============================ */
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

    /* ---------------------------------------------------------------------- */
    info_event("destroying SGX enclave");
    SGX_ASSERT( sgx_destroy_enclave( eid ) );

    info("all is well; exiting..");
	return 0;
}
