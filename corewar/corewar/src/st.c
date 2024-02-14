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

void get_st_args(int **args, process_t *process, things_t *things)
{
    args[0][0] = (int)get_single_byte(process, things);
    process->delta_pc += 1;
    if (args[1][1] == 1) {
        args[1][0] = get_single_byte(process, things);
        process->delta_pc += 1;
    } else {
        args[1][0] = (int)get_two_bytes(process, things);
    }
}

void st(int **args, process_t *process, things_t *things)
{
    get_st_args(args, process, things);
    if (args[1][1] == 1) {
        process->reg[args[1][0] - 1] = process->reg[args[0][0] - 1];
    } else {
        write_four_bytes(process->reg[PC] + args[1][0] % IDX_MOD, things,
process->reg[args[0][0] - 1]);
    }
}