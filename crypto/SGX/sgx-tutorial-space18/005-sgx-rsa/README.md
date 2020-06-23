# RSA: An elementary 16-bit crypto attack scenario

Cryptographic software is widely studied in side-channel attack research. This
exercise considers a toy enclave that implements a basic 16-bit version of the
RSA cryptosystem using the square-and-multiply algorithm with message blinding
protection.  The implementation is definitely not meant to be cryptographically
secure, but serves as an elementary case study application to analyze
side-channel leakage in enclave programs. 

## Background: Square and multiply

Modular exponentiation is the main ingredient of public key
algorithms such as RSA, and is commonly implemented using the
_square-and-multiply_ algorithm.  To compute _m = c^d_, square-and-multiply
iterates over the binary representation of _d_, repeatedly squaring _m_ each
iteration, and performing an extra multiplication of _m_ with _c_ in case the
bit in _d_ was set. Square-and-multiply thus branches on a secret each loop
iteration, making it a widely studied algorithm in side-channel analysis
research. Furthermore, naive implementations are known to be vulnerable to a
classical start-to-end execution timing attack that supplies carefully crafted
input messages to yield a measurable difference for individual key bits in the
total runtime of the program. The recommended countermeasure for this type of
timing attacks involves _message blinding_, where the input is masked with a
random factor before modular exponentiation takes place, and afterwards
canceled out.

## Your task

Your job is to extract the 16-bit private RSA key by observing side-effects
of the `ecall_rsa_decode` enclave entry point, which internally executes
square-and-multiply by iterating over the private key bits:

```C
int modpow(long long a, long long b, long long n)
{
    long long res = 1;
    uint16_t mask = 0x8000;

    for (int i=15; i >= 0; i--)
    {
        res = square(res, n);
        if (b & mask)
            res = multiply(res, a, n); 
        mask = mask >> 1;
    }
    return res;
}
```

**Note.** Real-world crypto libraries typically offer specialized helper
functions to multiply big numbers. This is abstracted in our rudimentary 16-bit
implementation by the dedicated `square` and `multiply` functions.

Some further guidance:

* The helper functions `square` and `multiply` are declared in `asm.S`, and are for
    this exercise explicitly allocated on separate code pages. (Again, note that
    this is often the case in real-world crypto libraries due to the complexity of
    the big number computation functions.)
* **For the enclave version, `modpow` is not expliticly aligned to a dedicated
    code page.** As such, the code for `modpow` may share a memory page with
    other enclave code, but your attack should still work if it correctly
    recognized page fault sequences.
* Simply monitoring the accesses on either `square` or `multiply` won't get you
    far, as this only reveals the _total_ number of one bits in the private key
    (which is supposed to be randomly distributed anyway).
* To reveal _individual_ private key bits, you will have to monitor the **page
    fault sequences** of the `square`, `multiply`, and `modpow` code pages with a
    simple state machine as follows:

![state-machine](state-machine.png)

* Be aware that `ecall_rsa_decode` first performs blinding on the input
    parameter through a `modpow` call with a _known_ exponent (rsa_e). As such,
    your attacker code will have to ignore the first call to `modpow` and only
    focus on page fault side-effects of the second `modpow` invocation with
    the secret argument (rsa_d). You can start with commenting out the first
    `modpow` call if that helps.
