# Mini-libc

## Statement

Build a **minimalistic** [**standard C library**](https://en.wikipedia.org/wiki/C_standard_library) implementation for Linux systems (named **mini-libc**), that can be used as a replacement for the **system libc** ([glibc](https://www.gnu.org/software/libc/) in Linux).
The goal is to have a minimally functional libc with features such as string management, basic memory support and POSIX file I/O.

The implementation of mini-libc will be **freestanding**, i.e. it will not use any outside library calls.
It will be implemented on top of the system call interface provided by Linux on an `x86_64` architecture.
Any function you require, that is typically part of libc, you will have to implement.
You can reuse functions that you implement in other parts of the mini-libc.

In case you are using a macOS device with ARM64 / Aarch64, you will have to install an `x86_64` virtual machine.

## Support Code

The support code consists of three directories:

- `src/` is the skeleton mini-libc implementation.
  You will have to implement missing parts marked as `TODO` items.

- `samples/` stores use cases and tests of mini-libc.

- `tests/` are tests used to validate (and grade) the assignment.

System call invocation is done via the `syscall()` function defined in `src/syscall.c`.
That itself makes a call to the architecture-specific call in `src/internal/arch/x86_64/syscall_arch.h`;
hence the dependency on the `x86_64` architecture.

