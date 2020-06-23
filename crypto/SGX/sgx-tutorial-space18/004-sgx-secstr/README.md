# To lower case: A secure string processing facility

Subtle side-channel vulnerabilities may arise in unexpected places.  In this
exercise we will explore how a seemingly harmless side-channel in one part of
the program, may compromise an unrelated secret in entirely another part of the
program.

## Your task

Consider the following enclave function that securely transforms a provided
input string to lower case characters.

```C
void ecall_to_lowercase(char *s)
{
    int i; char c;

    /* First ensure the _untrusted_ string lies outside the enclave */
    if (!sgx_is_outside_enclave(s, strlen(s)))
        return;

    /* Now transform the string character per character */
    for (i=0; i < strlen(s); i++)
        s[i] = to_lower(s[i]);
}
```

The above program is functionally correct. Go over the program line per line,
can you spot the subtle side-channel vulnerability?

The test enclave provides an `ecall_set_secret` entry point that places a
supposedly secret input value at a specific location inside the enclave (as
with the previous exercise, we provide an explicit `ecall_get_secret_adrs`
entry point to more easily obtain the address of the secret).  However, since
the secret is _never_ explicitly used inside the enclave, it should not be
possible for the attacker to obtain its value.

**Do it yourself.** Modify the untrusted main function to obtain the secret
value by observing side-effects of the `ecall_to_lowercase` enclave function.

Some guidance notes:

* Modern Intel processors feature a memory page size of 4096 (0x1000) bytes.
* You can make use of the
    [mprotect](http://man7.org/linux/man-pages/man2/mprotect.2.html) library
    function to alter page-granular access rights.
* SGX enclaves are loaded at runtime as a shared library object. This means
    that all addresses you obtain from an `objdump` need to be incremented with the
    base load address of the enclave. Enclave load addresses are
    attacker-controlled, and can hence be obtained by modifying the untrusted
    runtime, but we already provide you with an `ecall_get_secret_adrs`
    function to more easily get started.
* The provided skeleton program already takes care to redirect any page faults
    to the `fault_handler` function.
* Make sure to test both with an input `s=1` and `s=0` to make sure your attack
    proplerly handles both cases.

