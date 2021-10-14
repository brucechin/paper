/* utility headers */
#include "debug.h"
#include "pf.h"
#include "cacheutils.h"
#include <sys/mman.h>
#include "victim.h"

#define RSA_TEST_VAL    1234

int fault_fired = 0;
void *sq_pt = NULL, *mul_pt = NULL, *modpow_pt = NULL;

/* =========================== START SOLUTION =========================== */
/* =========================== END SOLUTION =========================== */

void fault_handler(void *base_adrs)
{
    /* =========================== START SOLUTION =========================== */
    /* =========================== END SOLUTION =========================== */

    fault_fired++;
}

int main( int argc, char **argv )
{
    int rv = 1, secret = 0;
    int cipher, plain;

    /* ---------------------------------------------------------------------- */
    info("registering fault handler..");
    register_fault_handler(fault_handler);

    /* ---------------------------------------------------------------------- */
    info_event("Calling enclave..");
    sq_pt = square;
    mul_pt = multiply;
    modpow_pt = GET_PFN(modpow);
    info("square at %p; muliply at %p; modpow at %p", sq_pt, mul_pt, modpow_pt);

    cipher = ecall_rsa_encode(RSA_TEST_VAL);
    plain = ecall_rsa_decode(cipher);
    info("secure enclave encrypted '%d' to '%d'; decrypted '%d'", RSA_TEST_VAL, cipher, plain);

    /* =========================== START SOLUTION =========================== */
    /* =========================== END SOLUTION =========================== */

    info("all is well; exiting..");
	return 0;
}
