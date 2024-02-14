BITS 64 ; 🛪🛪🛪🛪🛪🛪🛪🛪
GLOBAL strcasecmp

strcasecmp:
    ENTER 0, 0
    xor rax, rax

    .boucle:
        mov al, byte [rdi]
        mov dl, byte [rsi]
        cmp al, 0
        je .end
        cmp dl, 0
        je .end
        jmp .condition1

    .condition1:
        cmp al, 96
        JG .skip1

    .skip1:
        cmp al, 123
        jl .set1

    .set1:
        and al, 223
        jmp .condition2

    .condition2:
        cmp dl, 96
        JG .skip2

    .skip2:
        cmp dl, 123
        jl .set2

    .set2:
        and dl, 223
        jmp .continue

    .continue:
        cmp al, dl
        jne .end
        inc rdi
        inc rsi
        jmp .boucle

    .end:
        sub al, dl
        movsx rax, al
        LEAVE
        RET
