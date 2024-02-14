BITS 64 ; 🛪🛪🛪🛪🛪🛪🛪🛪
GLOBAL memmove

memmove:
    ENTER 0, 0
    XOR RAX, RAX
    xor rcx, rcx
    xor r8, r8
    cmp rdi, 0x0
    je .end
    cmp rsi, 0x0
    je .end
    cmp rdx, 0x0
    je .end

    .boucle:
        cmp rdi, rsi
        jle .upStr
        jmp .setupDownStr

    .upStr:
        cmp rax, rdx
        je .end
        cmp byte [rsi + rax], 0
        je .end
        mov cl, byte[rsi + rax]
        mov byte[rdi + rax], cl
        inc rax
        jmp .upStr

    .downStr:
        dec rax
        cmp rax, 0
        jl .end
        mov cl, byte[rsi + rax]
        mov byte[rdi + rax], cl
        jmp .downStr

    .setupDownStr:
        mov rax, rdx
        jmp .downStr

    .end:
        mov rax, rdi
        LEAVE
        RET
