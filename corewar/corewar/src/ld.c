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

void get_ld_args(int **args, process_t *process, things_t *things)
{
    if (args[0][1] == 2) args[0][0] = get_four_bytes(process, things);
    if (args[0][1] == 3) args[0][0] = get_two_bytes(process, things);
    args[1][0] = (int)get_single_byte(process, things);
    process->delta_pc += 1;
}

void ld(int **args, op_t op, process_t *process, things_t *things)
{
    int load;

    get_ld_args(args, process, things);
    if (args[0][1] == 2)
        load = args[0][0];
    if (args[0][1] == 3)
        load = get_adress_bytes(args[0][0] % IDX_MOD, things, process);
    process->reg[args[1][0] - 1] = load;
    if (load == 0)
        process->carry = 1;
    else
        process->carry = 0;

}