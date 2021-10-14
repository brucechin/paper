#ifndef CACHE_UTILS_H_INC
#define CACHE_UTILS_H_INC

/*
 * Code adapted from
 * https://github.com/IAIK/flush_flush/blob/master/sc/cacheutils.h
 */
uint64_t rdtsc_begin( void )
{
  uint64_t begin;
  uint32_t a, d;

  asm volatile (
    "mfence\n\t"
    "CPUID\n\t"
    "RDTSCP\n\t"
    "mov %%edx, %0\n\t"
    "mov %%eax, %1\n\t"
    "mfence\n\t"
    : "=r" (d), "=r" (a)
    :
    : "%eax", "%ebx", "%ecx", "%edx");

  begin = ((uint64_t)d << 32) | a;
  return begin;
}

uint64_t rdtsc_end( void )
{
  uint64_t end;
  uint32_t a, d;

  asm volatile(
    "mfence\n\t"
    "RDTSCP\n\t"
    "mov %%edx, %0\n\t"
    "mov %%eax, %1\n\t"
    "CPUID\n\t"
    "mfence\n\t"
    : "=r" (d), "=r" (a)
    :
    : "%eax", "%ebx", "%ecx", "%edx");

  end = ((uint64_t)d << 32) | a;
  return end;
}

/* 
 * Code adapted from: Yarom, Yuval, and Katrina Falkner. "Flush+ reload: a high
 * resolution, low noise, L3 cache side-channel attack." 23rd USENIX Security
 * Symposium (USENIX Security 14). 2014.
 */
int reload( void * adrs)
{
    volatile unsigned long time;

    asm volatile (
    "mfence\n\t"
    "lfence\n\t"
    "rdtsc\n\t"
    "lfence\n\t"
    "movl %%eax, %%esi\n\t"
    "movl (%1), %%eax\n\t"
    "lfence\n\t"
    "rdtsc\n\t"
    "subl %%esi, %%eax \n\t"
    : "=a" (time)
    : "c" (adrs)
    : "%rsi", "%rdx");

    return (int) time;
}

void flush(void* p)
{
    asm volatile (  "mfence\n"
            "clflush 0(%0)\n"
            "mfence\n"
      :
      : "D" (p)
      : "rax");
}

#endif
