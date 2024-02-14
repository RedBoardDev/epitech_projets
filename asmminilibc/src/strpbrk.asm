BITS 64 ; 🛪🛪🛪🛪🛪🛪🛪🛪
GLOBAL strpbrk

strpbrk:
    ENTER 0, 0
    XOR RAX, RAX
    mov RBX, RSI
    .boucle:
        cmp byte [RDI], 0
        je .endnull_strchr
        mov rdx, RBX
    .boucle_strchr:
        cmp byte [rdx], 0
        je .move
        mov al, byte [rdi]
        cmp al, [rdx]
        je .end_strchr
        inc rdx
        jmp .boucle_strchr
    .move:
        inc RDI
        jmp .boucle
    .endnull_strchr:
        XOR RAX, RAX
        LEAVE
        RET
    .end_strchr:
        MOV RAX, RDI
        LEAVE
        RET
