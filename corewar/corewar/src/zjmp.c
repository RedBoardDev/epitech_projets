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

void zjmp(char inst, process_t *process, things_t *things, op_t op)
{
    short a = (short)get_two_bytes(process, things);
    int b = a;

    if (process->carry == 1) process->delta_pc = process->reg[PC] +
b  % IDX_MOD;
}