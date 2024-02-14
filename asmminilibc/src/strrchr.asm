BITS 64 ; 🛪🛪🛪🛪🛪🛪🛪🛪
GLOBAL strrchr

strrchr:
    ENTER 0, 0
    XOR RAX, RAX
    .boucle:
        MOV cl, [RDI]
        CMP cl, 0x0
        JE .check
        CMP cl, sil
        JE .test
        INC RDI
        JMP .boucle

    .check:
        cmp sil, 0
        je .end
        jmp .endnull

    .test:
        XOR RAX, RAX
        MOV RAX, RDI
        INC RDI
        JMP .boucle

    .endnull:
        ; XOR RAX, RAX
        LEAVE
        RET
    .end:
        MOV RAX, RDI
        LEAVE
        RET
