BITS 64 ; 🛪🛪🛪🛪🛪🛪🛪🛪
GLOBAL strcmp

strcmp:
    ENTER 0, 0
    xor rax, rax

    .boucle:
        mov al, byte [rdi]
        mov dl, byte [rsi]
        cmp al, dl
        jne .end
        cmp al, 0
        je .end
        cmp dl, 0
        je .end
        inc rdi
        inc rsi
        jmp .boucle

    .end:
        sub al, dl
        movsx rax, al
        LEAVE
        RET
