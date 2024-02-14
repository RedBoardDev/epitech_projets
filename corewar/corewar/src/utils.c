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

int get_ind_adress_bytes(int adress, things_t *things, process_t *process)
{
    int out = 0;
    unsigned char tmp;

    for (int i = 0; i < 2; ++i) {
        tmp = things->arena[process->reg[PC] + adress + i];
        out += tmp;
        if (i < 1) out <<= 8;
    }
    return out;
}

int get_adress_bytes(int adress, things_t *things, process_t *process)
{
    int out = 0;
    unsigned char tmp;

    for (int i = 0; i < 4; ++i) {
        tmp = things->arena[process->reg[PC] + adress + i];
        out += tmp;
        if (i < 3) out <<= 8;
    }
    return out;
}

int rev_int(int in)
{
    int out = 0;
    unsigned char buf;

    for (int i = 0; i < 4; ++i, in >>= 8) {
        buf = in % 256;
        for (int j = 0; j < 8; ++j, buf <<= 1) {
            out <<= 1;
            (buf & 128) ? (++out) : (0);
        }
    }
    return out;
}

void cp_in_string(char const *in, char *out)
{
    int i = 0;

    for (; in[i]; ++i)
        out[i] = in[i];
    out[i] = 0;
}
