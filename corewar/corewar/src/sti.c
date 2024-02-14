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

void write_four_bytes(int adress, things_t *things, int nb)
{
    unsigned char temp;
    int tmp;

    for (int i = 0; i < 4; ++i) {
        tmp = nb >> 32 - ((i + 1) * 8);
        temp = tmp & 255;
        things->arena[adress + i] = temp;
    }
}

void get_sti_args(int **args, process_t *process, things_t *things)
{
    args[0][0] = (int)get_single_byte(process, things);
    process->delta_pc += 1;
    if (args[1][1] == 1) {
        args[1][0] = get_single_byte(process, things);
        process->delta_pc += 1;
    } else
        args[1][0] = (int)get_two_bytes(process, things);
    if (args[2][1] == 1) {
        args[2][0] = get_single_byte(process, things);
        process->delta_pc += 1;
    } else
        args[2][0] = (int)get_two_bytes(process, things);
}

void sti(int **args, op_t op, process_t *process, things_t *things)
{
    int a;
    int b;
    int out;

    get_sti_args(args, process, things);
    if (args[1][1] == 1) a = process->reg[args[1][0] - 1];
    if (args[1][1] == 2) a = args[1][0];
    if (args[1][1] == 3) a = get_adress_bytes(args[1][0], things, process);
    if (args[2][1] == 1) b = process->reg[args[2][0] - 1];
    if (args[2][1] == 2) b = args[2][0];
    write_four_bytes(process->reg[PC] + (a + b) % IDX_MOD, things,
process->reg[args[0][0] - 1]);
}
