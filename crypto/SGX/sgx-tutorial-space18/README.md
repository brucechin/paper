# Tutorial overview and objectives

This repository collects presentation material and source code for hands-on
exercises part of a 3h tutorial taught at the 8th International Conference on
Security, Privacy, and Applied Cryptography Engineering
([SPACE18](https://space2018.cse.iitk.ac.in/)), held 2018 December 15, Kanpur,
India.

## Abstract

The inclusion of the Software Guard eXtensions (SGX) in recent Intel processors
has been broadly acclaimed for bringing strong hardware-enforced trusted
computing guarantees to mass consumer devices, and for protecting end user data
in an untrusted cloud environment.  While SGX assumes a very strong attacker
model and indeed even safeguards enclave secrets against a compromised
operating system, recent research has demonstrated that considerable private
data (e.g., full text and images, complete cryptographic keys) may still be
reconstructed by monitoring subtle side-effects of the enclaved execution.

We argue that a systematic understanding of such side-channel leakage sources
is essential for writing intrinsically secure enclave applications, and will be
instrumental to the success of this new trusted execution technology.  This
tutorial and write-up therefore aims to bring a better understanding of current
state-of-the-art side-channel attacks and defenses on Intel SGX platforms.
Participants will learn how to extract data from elementary example
applications, thereby recognizing how to avoid common pitfalls and information
leakage sources in enclave development.

> Jo Van Bulck, Frank Piessens "Tutorial: Uncovering and mitigating side-channel
> leakage in Intel SGX enclaves", 8th International Conference on Security,
> Privacy, and Applied Cryptography Engineering (SPACE'18). December 2018.

## Tutorial organization

This tutorial is aimed at a target audience of C programmers with an interest
in security. The tutorial takes about three hours, with an equal split between
lectures and practical exercises.

**Note (SGX support).** Since we do not assume that all participants have
access to an [SGX-capable](https://github.com/ayeks/SGX-hardware) Intel
processor, plus [linux-sgx](https://github.com/01org/linux-sgx) toolchain, we
made sure that all exercises have both an _unprotected_ and _enclaved_ version.
For the SPACE2018 tutorial setting, we will provide SSH access to an SGX
machine over the local network in order to test the enclaved version.

However, to keep pressure on the remote SSH SGX machine low, *we strongly
advise to first develop the unprotected attack scenario on your local x86
machine, before testing the enclaved version on the remote SGX machine via
SSH.* Once the unprotected version is working, it should be relatively
straightforward to port the attack to an SGX setting.

**Note (solutions).** This git repository includes a
[`solutions`](https://github.com/jovanbulck/sgx-tutorial-space18/tree/solutions)
branch with working attack code for all of the exercises. If you want to solve
the exercise challenges on your own, you should of course only verify your
solutions after having implemented the attack yourself using the skeleton code
provided in the default `master` branch.


| Program                   | SGX enclave version      | Description                                        |
|---------------------------|--------------------------|----------------------------------------------------|
| **001-pwd**               | 001-sgx-pwd              | Basic _timing_ side-channel attack.                |
| **002-inc-secret**        | 002-sgx-inc-secret       | Basic _page fault_ side-channel attack.            |
| **003-flush-and-reload**  | 003-sgx-flush-and-reload | Flush+Reload _cache_ attack on unprotected memory. |
| **004-str**               | 004-sgx-str              | More subtle _page fault_ side-channel attack.      |
| **005-rsa**               | 005-sgx-rsa              | Page _fault sequence_ side-channel attack.         |

## License

You are welcome to re-use all of the material in this repository for your own
teaching (given appropriate credit). All exercise code is free software,
licensed under [GPLv3](https://www.gnu.org/licenses/gpl-3.0).
Presentation material (slides) are released on a
[CC-BY](https://creativecommons.org/licenses/by/4.0/) basis. 

