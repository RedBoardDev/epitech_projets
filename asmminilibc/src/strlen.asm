BITS 64 ; 🛪🛪🛪🛪🛪🛪🛪🛪
GLOBAL strlen

strlen:
    ENTER 0, 0
    MOV RAX, 0
    .boucle:
        CMP BYTE [RDI], 0
        JE .end
        INC RDI
        INC RAX
        JMP .boucle
    .end:
        LEAVE
        RET
