BITS 64 ; 🛪🛪🛪🛪🛪🛪🛪🛪
GLOBAL memcpy

memcpy:
    enter 0, 0
    xor rax, rax
    xor rcx, rcx
    xor r8, r8
    cmp rdi, 0x0
    je .end
    cmp rsi, 0x0
    je .end
    cmp rdx, 0x0
    je .end

    .boucle:
        cmp rdx, rcx
        je .end
        mov al, rsi[rcx]
        mov rdi[rcx], al
        inc rcx
        jmp .boucle
    .end:
        xor rax, rax
        mov rax, rdi
        LEAVE
        RET
