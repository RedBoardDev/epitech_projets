BITS 64 ; 🛪🛪🛪🛪🛪🛪🛪🛪
GLOBAL strcspn

strcspn:
    ENTER 0, 0
    XOR RAX, RAX
    .boucle:
        ; xor RAX, RAX
        xor rdx, rdx
        ; mov rdx, rdi
        mov rdx, rsi ; move second arg on buffer
        cmp dl, 0x0 ; si on est a la fin de l'arg 2 on recommence du debut
        je .move

    .boucle_strchr:
        MOV cl, [rdx]
        CMP cl, 0x0
        je .move
        ; CMP cl, byte [rsi]
        cmp cl, byte [rdi] ; si le char de rdi = char de rsi
        JE .end_strchr
        INC rdx
        JMP .boucle_strchr

    .move:
        ; cmp byte [rsi], 0x0
        cmp byte [rdi], 0x0 ; si je suis a la fin de l'arg 1 je leave
        je .end_strchr
        inc RAX
        ; inc rsi
        inc rdi ; move first arg
        jmp .boucle

    .endnull_strchr:
        MOV RAX, 0x0
        LEAVE
        RET

    .end_strchr:
        LEAVE
        RET
