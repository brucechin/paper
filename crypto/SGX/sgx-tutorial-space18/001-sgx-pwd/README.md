# PIN code verifier: your  first enclave program

## Application overview

The purpose of this application is to develop a first elementary SGX enclave
program that verifies untrusted user input. Particularly, we assume that the
enclave has previously already been securely provisioned with a 4-digit PIN
code and an application-level secret. The enclave's sole job is to enforce
access control on the application secret by querying the untrusted world for
the PIN code, destroying the secret after three successive failed comparison
attempts, or returning it on success.

**Note.** This application only serves demonstration purposes and does not aim
to be a fully tamper-proof security solution. Notable enclave concepts that are
missing include _secure I/O_, _secret provisioning_, _sealing_ for persistent
storage, and _state continuity_ to protect against roll-back attacks.

## Your task

Developing an SGX enclave application roughly falls down in three phases,
outlined below.

### Extending enclave public interface (`Enclave/encl.edl`)

In the enclaved execution paradigm, the programmer splits off a small trusted
application part (the "enclave") that is shielded by the CPU from the remainder
of the application. Since enclaves are designed to operate in an untrusted,
potentially hostile, environment, they should enforce a strict public software
interface. Generally, enclaves can interact with their untrusted environment in
two distinct ways:

- **ECALL:** Function call performed by the untrusted world to enter an
  enclave, passing some arguments and/or expecting a return value.
- **OCALL:** Function call performed by the enclave to call back to the
  untrusted world, passing some arguments and/or expecting a return value.

The Intel SGX SDK features a small domain-specific [Enclave Definition Language
(EDL)](https://software.intel.com/en-us/sgx-sdk-dev-reference-enclave-definition-language-file-syntax)
to unambiguously define the enclave's ECALL/OCALL interaction with the
untrusted world. Pointer arguments should be explicitly marked with `[in]` and
`[out]` attributes to indicate whether they represent input and/or output for
the enclave (in case of an ECALL), or untrusted world (in case of an OCALL).
Based on this description, the SDK automatically generates trusted and
untrusted bridge code that securely transfers control to/from the untrusted
environment.

**Do it yourself.** The PIN code verifier application will feature an ECALL
entry point to try and request the application secret by verifying an untrusted
PIN code from the end user. You will thus have to:

- Extend `Enclave/encl.edl` with a trusted `ecall_get_secret` ECALL entry point
  that takes an `int*` and a `char*` pointer arguments and returns an `int`,
  indicating whether or not PIN code verification succeeded and the application
  secret was written to the pointer argument.

### Extending enclave implementation (`Enclave/encl.c`)

After defining the enclave's interface, you will have to implement the required
ECALL functionality. Implement the `int ecall_get_secret(int *secret_pt)`
function by making use of the `int ocall_get_pin(char *)` untrusted helper
function. Take care to ensure that:

- The enclave only writes `super_secret_constant` to `secret_pt` when the
  untrusted user-provided PIN code exactly matches `SECRET_PIN` of length
  `SECRET_LEN`.

### Extending untrusted runtime (`main.c`)

Finally, after finishing the trusted enclave's implementation, you have to
extend the untrusted runtime support system. We already provided the enclave
creation code, `ocall_get_pin` function, and an example `ecall_dummy()` enclave
function call. Now, add the `ecall_get_secret()` enclave function call, and
print out the return value and secret returned by the trusted enclave.

## Building and running

Simply execute:

```bash
$ make run
```

**Explain.** Do you succeed in reproducing the timing side-channel attack of
the untrusted program in an enclave setting. Explain why (not)? What doest this
tell you about the _signal-to-noise_ ratio for timing enclave programs? 
