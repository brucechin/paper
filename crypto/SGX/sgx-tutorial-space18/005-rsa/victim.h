#ifndef VICTIM_H_INC
#define VICTIM_H_INC

#include <stdint.h>

/* See asm.S */
uint64_t square(uint64_t a, uint64_t n);
uint64_t multiply(uint64_t a, uint64_t b, uint64_t n);
int modpow(long long a, long long b, long long n);

int ecall_rsa_encode(int plain);
int ecall_rsa_decode(int cipher);

#endif
