BITS 64 ; 🛪🛪🛪🛪🛪🛪🛪🛪
GLOBAL strstr

strlen:
    ENTER 0, 0
    MOV RAX, 0
    .boucle_strlen:
        CMP BYTE [r9], 0
        JE .end_strlen
        INC r9
        INC RAX
        JMP .boucle_strlen
    .end_strlen:
        LEAVE
        RET

strncmp:
    ENTER 0, 0
    xor rax, rax
    xor rcx, rcx
    .boucle_strncmp:
        cmp R10, rcx
        je .end_feur
        mov r14b, byte [R12]
        mov R13B, byte [R11]
        cmp r14b, R13B
        jne .end_strncmp
        cmp r14b, 0
        je .end_strncmp
        cmp R13B, 0
        je .end_strncmp
        inc R12
        inc R11
        inc rcx
        jmp .boucle_strncmp

    .end_strncmp:
        sub al, R13B
        movsx rax, al
        LEAVE
        RET

    .end_feur:
        mov rax, 0
        LEAVE
        RET

strstr:
    ENTER 0, 0
    xor rax, rax

    mov R9, rsi
    call strlen
    cmp rax, 0
    je .rsi_empty
    mov R10, rax
    xor rax, rax

    .boucle:
        cmp byte [rdi], 0x0
        je .end_notfound
        mov R11, rsi
        mov R12, rdi
        call strncmp

        cmp byte rdi, 0x0
        je .end_notfound
        cmp byte rsi, 0x0
        je .end

        cmp rax, 0x0
        je .end
        inc rdi
        jmp .boucle

    .rsi_empty:
        mov rax, rdi
        LEAVE
        RET
    .end:
        mov rax, rdi
        LEAVE
        RET
    .end_notfound:
        mov rax, 0
        LEAVE
        RET
