#ifndef VICTIM_H_INC
#define VICTIM_H_INC

extern char *secret_pt;

void ecall_set_secret(char b);

void ecall_to_lowercase(char *s);

#endif
