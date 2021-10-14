#ifndef VICTIM_H_INC
#define VICTIM_H_INC

/* see asm.S */
extern int a;

void ecall_inc_secret(int s);

void ecall_inc_secret_maccess(int s);

#endif
