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

void get_sub_args(int **args, process_t *process, things_t *things)
{
    args[0][0] = (int)get_single_byte(process, things);
    process->delta_pc += 1;
    args[1][0] = (int)get_single_byte(process, things);
    process->delta_pc += 1;
    args[2][0] = (int)get_single_byte(process, things);
    process->delta_pc += 1;
}

void sub(int **args, op_t op, process_t *process, things_t *things)
{
    get_sub_args(args, process, things);
    process->reg[args[2][0]] = process->reg[args[1][0]] -
process->reg[args[0][0]];
}