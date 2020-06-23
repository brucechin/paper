#ifndef PF_H_INC
#define PF_H_INC

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PFN_MASK 0xfff 

#define GET_PFN(adrs) ((void*) (((uint64_t) adrs) & ~PFN_MASK))

typedef void (*fault_handler_t)(void *page_base_adrs);
void register_fault_handler(fault_handler_t cb);

#endif
