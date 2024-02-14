/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main_corewar.c
*/

#include "../include/corewar.h"
#include "../include/preprocessor.h"
#include "../include/op.h"
#include <stdlib.h>
#include <stdio.h>

void add_fork(process_t **all_process, process_t *src, int pc)
{
    process_t *temp = malloc(sizeof(process_t));
    temp->carry = src->carry;
    temp->current = 0;
    temp->prog_size = src->prog_size;
    temp->magic = src->magic;
    temp->reg = malloc(sizeof(int) * (REG_NUMBER));
    for (int i = 0; i < REG_NUMBER; ++i)
        temp->reg[i] = src->reg[i];
    temp->reg[0] = src->reg[0];
    temp->reg[PC] = src->reg[PC] + pc % IDX_MOD;
    temp->delta_pc = temp->reg[PC];
    temp->next = *all_process;
    *all_process = temp;
}

void my_fork(char inst, process_t *process, things_t *things, op_t op)
{
    short a = (short)get_two_bytes(process, things);
    int b = a;

    add_fork(&things->all_process, process, b);
    things->nb_champ += 1;
}