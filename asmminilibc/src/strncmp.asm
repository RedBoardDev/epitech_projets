BITS 64 ; 🛪🛪🛪🛪🛪🛪🛪🛪
GLOBAL strncmp

strncmp:
    ENTER 0, 0
    xor rax, rax
    sub rdx, 1
    xor rcx, rcx
    .boucle:
        cmp rdx, rcx
        je .end_feur
        mov al, byte [rdi]
        mov R8B, byte [rsi]
        cmp al, R8B
        jne .end
        cmp al, 0
        je .end
        cmp R8B, 0
        je .end
        inc rdi
        inc rsi
        inc rcx
        jmp .boucle

    .end:
        sub al, R8B
        movsx rax, al
        LEAVE
        RET

    .end_feur:
        mov rax, 0
        LEAVE
        RET
