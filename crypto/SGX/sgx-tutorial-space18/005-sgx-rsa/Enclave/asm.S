    .text
    .global square
    .align 0x1000   /* 4KiB */
square:
    mov    %rdi,%rax
    xor    %edx,%edx
    imul   %rdi,%rax
    div    %rsi
    mov    %rdx,%rax
    retq   
    .space 0x1000   /* 4KiB */

    .text
    .global multiply
    .align 0x1000   /* 4KiB */
multiply:
    mov    %rdi,%rax
    mov    %rdx,%rcx
    xor    %edx,%edx
    imul   %rsi,%rax
    div    %rcx
    mov    %rdx,%rax
    retq  
    .space 0x1000   /* 4KiB */
