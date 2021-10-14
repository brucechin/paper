/* utility headers */
#include "debug.h"
#include "pf.h"
#include "cacheutils.h"
#include <sys/mman.h>
#include "victim.h"

int fault_fired = 0;

void fault_handler(void *base_adrs)
{
    /* =========================== START SOLUTION =========================== */
    /* =========================== END SOLUTION =========================== */

    fault_fired++;
}

int main( int argc, char **argv )
{
    int rv = 1, secret = 0;

    /* ---------------------------------------------------------------------- */
    info("registering fault handler..");
    register_fault_handler(fault_handler);
    info("a at %p\n", &a);

    /* ---------------------------------------------------------------------- */
    info_event("inc_secret attack");

    /* =========================== START SOLUTION =========================== */
    /* =========================== END SOLUTION =========================== */

    /* ---------------------------------------------------------------------- */
    info_event("inc_secret_maccess attack");

    /* =========================== START SOLUTION =========================== */
    /* =========================== END SOLUTION =========================== */

    /* ---------------------------------------------------------------------- */

    info("all is well; exiting..");
	return 0;
}
