/*
** EPITECH PROJECT, 2021
** corewar-
** File description:
** display_header.c
*/

#include "../include/asm.h"
#include "../include/op.h"

void display_head(header_t *head, int fd, instr_bit_t *instr_bit, int nbr_line)
{
    int size = 0;

    for (int i = 0; i < nbr_line; ++i)
        for (int r = 0; r < instr_bit[i].len; ++r)
            size += instr_bit[i].stock_nb[r];
    head->prog_size = SWAP_UINT32(size);
    head->magic = COREWAR_EXEC_MAGIC;
    write(fd, head, sizeof(header_t));
}
