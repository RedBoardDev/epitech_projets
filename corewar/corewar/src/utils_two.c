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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char get_single_byte(process_t *process, things_t *things)
{
    return things->arena[process->delta_pc];
}

int get_two_bytes(process_t *process, things_t *things)
{
    int out = 0;
    unsigned char tmp = things->arena[process->delta_pc];

    out += tmp;
    out <<= 8;
    process->delta_pc += 1;
    tmp = things->arena[process->delta_pc];
    out += tmp;
    process->delta_pc += 1;
    return out;
}

int get_four_bytes(process_t *process, things_t *things)
{
    int out = 0;
    unsigned char tmp;

    for (int i = 0; i < 4; ++i) {
        tmp = things->arena[process->delta_pc];
        out += tmp;
        process->delta_pc += 1;
        if (i < 3) out <<= 8;
    }
    return out;
}
