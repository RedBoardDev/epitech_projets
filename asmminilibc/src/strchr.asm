BITS 64 ; 🛪🛪🛪🛪🛪🛪🛪🛪
GLOBAL strchr

strchr:
    ENTER 0, 0
    XOR RAX, RAX
    .boucle:
        MOV cl, [RDI]
        CMP cl, 0x0
        JE .check
        CMP cl, sil
        JE .end
        INC RDI
        JMP .boucle

    .check:
        cmp sil, 0
        je .end
        je .endnull

    .endnull:
        XOR RAX, RAX
        LEAVE
        RET
    .end:
        MOV RAX, RDI
        LEAVE
        RET
