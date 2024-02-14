BITS 64 ; 🛪🛪🛪🛪🛪🛪🛪🛪
GLOBAL memset

memset:
    enter 0, 0
    xor rax, rax
    xor rcx, rcx
    .boucle:
        cmp rdx, rcx
        je .end
        mov rdi[rcx], sil
        inc rcx
        JMP .boucle
    .end:
        mov rax, rdi
        LEAVE
        RET
