/* utility headers */
#include "debug.h"
#include "pf.h"
#include "cacheutils.h"
#include <sys/mman.h>
#include <string.h>
#include "victim.h"

#define TEST_STRING     "DeaDBEeF"

int fault_fired = 0;
void *page_pt = NULL;

void fault_handler(void *base_adrs)
{
    /* =========================== START SOLUTION =========================== */
    /* =========================== END SOLUTION =========================== */

    fault_fired++;
}

int main( int argc, char **argv )
{
    int rv = 1, secret = 0;
    char *string;

    /* ---------------------------------------------------------------------- */
    info("registering fault handler..");
    register_fault_handler(fault_handler);

    info("secret at %p\n", secret_pt);

    /* ---------------------------------------------------------------------- */
    info_event("Calling enclave..");
    string = malloc(strlen(TEST_STRING)+1);
    strcpy(string, TEST_STRING); 
    ecall_to_lowercase(string);
    info("secure enclave converted '%s' to '%s'", TEST_STRING, string);

    /* =========================== START SOLUTION =========================== */
    /* =========================== END SOLUTION =========================== */
    
    info("all is well; exiting..");
	return 0;
}
