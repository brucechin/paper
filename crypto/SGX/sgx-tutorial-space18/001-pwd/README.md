# A hands-on guide to execution timing attacks

As a warm-up exercise, we will start by explaining the concept of a timing
side-channel by attacking a rudimentary example program. The program compares a
user-provided input against an unknown secret PIN code to decide access.
Your task is to infer the secret PIN code, without modifying any of the code.
For this, you will have to cleverly provide inputs to the program, and
carefully observe the associated execution timings being printed.

## Your task

Try to understand what the passwd program is doing by examining its source code
(`passwd.c`). However, make sure to not yet open the `secret.h` file at this
point, or you'll miss out on all the fun! ;-)

**Note.** This program does not yet require Intel SGX support, but can only be
executed on a (recent) Intel/AMD x86 processor, which is most likely what's in
your laptop (if you don't get any error messages).

### Identifying the timing channel

After running and/or examining the program, you will have noticed that the only
way to get access is to provide the unknown PIN code.  However, besides
printing an "access denied" message, the program also prints a timing
measurement. More specifically, it prints the amount of CPU cycles needed to
execute the `check_pwd` function below (expressed as the median over 100,000
repeated runs):

```C
int check_pwd(char *user, int user_len, char *secret, int secret_len)
{
    int i;

    /* reject if incorrect length */
    if (user_len != secret_len)
        return 0;

    /* reject on first byte mismatch */
    for (i=0; i < user_len; i++)
    {
        if (user[i] != secret[i])
            return 0;
    }

    /* user password passed all the tests */
    return 1;
}
```

**Note.** The above code is somewhat simplified. The real C program includes
additional dummy `delay` function calls to artificially delay the
program, with the purpose of amplifying the timing channel for educational
purposes.

**Do it yourself.** Explain why the execution timings being printed are not not
always exactly the same when repeatedly providing the exact same input.  Why is
it a good idea to print the median instead of the average?

> Execution time non-determinism in modern processors is caused by a wide range
> of microarchitectural optimizations including (instruction+data) caching,
> pipelining, branch prediction, dynamic frequency scaling, etc.  Ultimately, a
> single execution timing measurement may be unreliable, and it's better to
> aggregate over multiple measurements.  We compute the the median, since a
> single outlier (e.g., due to an operating system context switch or interrupt)
> may strongly affect the average.

The `check_pwd` function performs the actual password comparison, and only returns
1 if the password string pointed to by the `user` argument
exactly matches a `secret` string. Otherwise a return value of zero is returned.
While this is clearly functionally correct behavior, `check_pwd` does not
always execute the same instructions for every input.

### Exploiting the timing channel

Keep in mind that you only control the `user` and `user_len`
arguments (by providing inputs to the program), while `secret` and `secret_len`
remain fixed unknown values.

**Do it yourself.** Try to come up with a way to iteratively provide inputs and
learn something useful from the associated timings. First infer `secret_len`,
before finally inferring all the `secret` bytes.  You can assume the secret PIN
code uses only numeric digits (0-9).

