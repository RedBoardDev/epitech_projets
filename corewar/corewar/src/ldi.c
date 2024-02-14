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

void get_ldi_args(int **args, process_t *process, things_t *things)
{
    args[0][0] = (int)get_two_bytes(process, things);
    args[1][0] = (int)get_two_bytes(process, things);
    args[2][0] = (int)get_single_byte(process, things);
    process->delta_pc += 1;
}

void ldi(int **args, op_t op, process_t *process, things_t *things)
{
    int a;
    int b;

    get_ldi_args(args, process, things);
    if (args[0][1] == 1) a = process->reg[args[0][0] - 1];
    if (args[0][1] == 2) a = args[0][0];
    if (args[0][1] == 3) a = get_ind_adress_bytes(args[0][0] % IDX_MOD,
things, process);
    if (args[1][1] == 1) b = process->reg[args[1][0] - 1];
    if (args[1][1] == 2) b = args[1][0];
    process->reg[args[2][0] - 1] = get_adress_bytes((a + b) % IDX_MOD,
things, process);
    if ((a + b) % IDX_MOD == 0)
        process->carry = 1;
    else
        process->carry = 0;
}