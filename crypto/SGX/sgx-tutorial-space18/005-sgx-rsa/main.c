/* utility headers */
#include "debug.h"
#include "pf.h"
#include "cacheutils.h"
#include <sys/mman.h>

/* SGX untrusted runtime */
#include <sgx_urts.h>
#include "Enclave/encl_u.h"

#define RSA_TEST_VAL    1234

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
    sgx_enclave_id_t eid = create_enclave();
    int rv = 1, secret = 0;
    int cipher, plain;

    /* ---------------------------------------------------------------------- */
    info("registering fault handler..");
    register_fault_handler(fault_handler);

    /* ---------------------------------------------------------------------- */
    info_event("Calling enclave..");
    SGX_ASSERT( ecall_get_square_adrs(eid, &sq_pt) );
    SGX_ASSERT( ecall_get_multiply_adrs(eid, &mul_pt) );
    SGX_ASSERT( ecall_get_modpow_adrs(eid, &modpow_pt) );
    modpow_pt = (void*) (((uint64_t) modpow_pt) & ~0xfff);
    info("square at %p; muliply at %p; modpow at %p", sq_pt, mul_pt, modpow_pt);

    SGX_ASSERT( ecall_rsa_encode(eid, &cipher, RSA_TEST_VAL) );
    SGX_ASSERT( ecall_rsa_decode(eid, &plain, cipher) );
    info("secure enclave encrypted '%d' to '%d'; decrypted '%d'", RSA_TEST_VAL, cipher, plain);

    /* =========================== START SOLUTION =========================== */
    /* =========================== END SOLUTION =========================== */

    info_event("destroying SGX enclave");
    SGX_ASSERT( sgx_destroy_enclave( eid ) );

    info("all is well; exiting..");
	return 0;
}
