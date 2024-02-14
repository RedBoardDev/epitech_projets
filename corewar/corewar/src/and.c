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

void get_and_args(int **args, process_t *process, things_t *things)
{
    if (args[0][1] == 1) {
        args[0][0] = get_single_byte(process, things);
        process->delta_pc += 1;
    }
    if (args[0][1] == 2)
        args[0][0] = (int)get_four_bytes(process, things);
    if (args[0][1] == 3)
        args[0][0] = (int)get_two_bytes(process, things);
    if (args[1][1] == 1) {
        args[1][0] = get_single_byte(process, things);
        process->delta_pc += 1;
    }
    if (args[1][1] == 2)
        args[1][0] = (int)get_four_bytes(process, things);
    if (args[1][1] == 3)
        args[1][0] = (int)get_two_bytes(process, things);
    args[2][0] = get_single_byte(process, things);
    process->delta_pc += 1;
}

void and(int **args, op_t op, process_t *process, things_t *things)
{
    int a;
    int b;

    get_and_args(args, process, things);
    if (args[0][1] == 1) a = process->reg[args[1][0] - 1];
    if (args[0][1] == 2) a = args[1][0];
    if (args[0][1] == 3) a = get_adress_bytes(args[1][0], things, process);
    if (args[1][1] == 1) b = process->reg[args[1][0] - 1];
    if (args[1][1] == 2) b = args[1][0];
    if (args[1][1] == 3) a = get_adress_bytes(args[1][0], things, process);
    process->reg[args[2][0] - 1] = a & b;
    if (a & b == 0)
        process->carry = 1;
    else
        process->carry = 0;
}