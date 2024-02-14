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

void aff(int **args, op_t op, process_t *process, things_t *things)
{
    char a = get_single_byte(process, things);
    process->delta_pc += 1;
    char str[1] = {process->reg[a - 1] % 256};
    write(1, str, 1);
}