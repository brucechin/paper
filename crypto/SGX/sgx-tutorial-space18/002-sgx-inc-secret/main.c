/* utility headers */
#include "debug.h"
#include "pf.h"
#include "cacheutils.h"
#include <sys/mman.h>

/* SGX untrusted runtime */
#include <sgx_urts.h>
#include "Enclave/encl_u.h"

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
void *a_pt = NULL;

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

    /* ---------------------------------------------------------------------- */
    info("registering fault handler..");
    register_fault_handler(fault_handler);

    SGX_ASSERT( ecall_get_a_adrs(eid, &a_pt) );
    info("a at %p\n", a_pt);

    /* ---------------------------------------------------------------------- */
    info_event("inc_secret attack");

    /* =========================== START SOLUTION =========================== */
    /* =========================== END SOLUTION =========================== */

    /* ---------------------------------------------------------------------- */
    info_event("inc_secret_maccess attack");

    /* =========================== START SOLUTION =========================== */
    /* =========================== END SOLUTION =========================== */

    /* ---------------------------------------------------------------------- */
    info_event("destroying SGX enclave");
    SGX_ASSERT( sgx_destroy_enclave( eid ) );

    info("all is well; exiting..");
	return 0;
}
