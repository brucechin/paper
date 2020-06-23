#include "debug.h"
#include "pf.h"
#include <signal.h>
#include <string.h>

fault_handler_t __fault_handler_cb = NULL;

void fault_handler_wrapper (int signo, siginfo_t * si, void  *ctx)
{
  void *base_adrs;
  ucontext_t *uc = (ucontext_t *) ctx;

  switch ( signo )
  {
    case SIGSEGV:
      base_adrs = si->si_addr;
      info("Caught page fault (base address=%p)", base_adrs);
      break;

    default:
      info("Caught unknown signal '%d'", signo);
      abort();
  }

  /* Mask lower PFN bits to simulate clearing by SGX hardware when executing
     the unprotected programs */
  base_adrs = GET_PFN(base_adrs);

  if (__fault_handler_cb)
    __fault_handler_cb(base_adrs);
}

void register_fault_handler(fault_handler_t cb)
{
  struct sigaction act, old_act;
  memset(&act, sizeof(sigaction), 0);

  /* Specify handler with signinfo arguments */
  act.sa_sigaction = fault_handler_wrapper;
  act.sa_flags = SA_RESTART | SA_SIGINFO;

  /* Block all signals while the signal is being handled */
  sigfillset(&act.sa_mask);

  ASSERT (!sigaction( SIGSEGV, &act, &old_act ));

  __fault_handler_cb = cb;
}
