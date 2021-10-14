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
supposedly secret input value at a specific location `secret_pt` inside the
"enclave" (`victim.c`).  However, since the secret is _never_ explicitly used
inside the enclave, it should not be possible for the attacker to obtain its
value.

**Do it yourself.** Modify the untrusted main function to obtain the secret
value by observing side-effects of the `ecall_to_lowercase` enclave function.

Some guidance notes:

* Modern Intel processors feature a memory page size of 4096 (0x1000) bytes.
* You can make use of the
    [mprotect](http://man7.org/linux/man-pages/man2/mprotect.2.html) library
    function to alter page-granular access rights.
* The provided skeleton program already takes care to redirect any page faults
    to the `fault_handler` function.
* Make sure to test both with an input `s=1` and `s=0` to make sure your attack
    proplerly handles both cases.

### Launching the attack on real SGX hardware

Now you have the proof-of-concept attack working in an _unprotected_
application on your own laptop, proceed to the `../004-sgx-secstr` program
to try and port your attack to a real Intel x86 SGX processor.
