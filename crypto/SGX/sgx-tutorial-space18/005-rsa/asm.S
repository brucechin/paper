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

    .text
    .global modpow
    .align 0x1000   /* 4KiB */
modpow:
    push   %rbp
    mov    %rsp,%rbp
    sub    $0x30,%rsp
    mov    %rdi,-0x18(%rbp)
    mov    %rsi,-0x20(%rbp)
    mov    %rdx,-0x28(%rbp)
    movq   $0x1,-0x8(%rbp)
    movw   $0x8000,-0xa(%rbp)
    movl   $0xf,-0x10(%rbp)
    jmp    3f
1:  
    mov    -0x28(%rbp),%rdx
    mov    -0x8(%rbp),%rax
    mov    %rdx,%rsi
    mov    %rax,%rdi
    callq  square
    mov    %rax,-0x8(%rbp)
    movzwl -0xa(%rbp),%eax
    and    -0x20(%rbp),%rax
    test   %rax,%rax
    je     2f
    mov    -0x28(%rbp),%rdx
    mov    -0x18(%rbp),%rcx
    mov    -0x8(%rbp),%rax
    mov    %rcx,%rsi
    mov    %rax,%rdi
    callq  multiply
    mov    %rax,-0x8(%rbp)
2:  
    shrw   -0xa(%rbp)
    subl   $0x1,-0x10(%rbp)
3:  
    cmpl   $0x0,-0x10(%rbp)
    jns    1b
    mov    -0x8(%rbp),%rax
    leaveq 
    retq   

    .space 0x1000   /* 4KiB */
