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

void cp_on_arena(char *arena, char *prog, int size, int ind)
{
    int a = 0;

    for (int i = ind; i < ind + size; ++i) {
        arena[i] = prog[a];
        ++a;
    }
}

void init_arena(things_t *things)
{
    process_t *temp;
    int i = 0;
    int pos;

    temp = things->all_process;
    while (temp != NULL) {
        pos =  (temp->load_adresse != -1) ? (temp->load_adresse) :
((MEM_SIZE / things->nb_champ) * i);
        cp_on_arena(things->arena, temp->prog, temp->prog_size, pos);
        temp->reg[REG_NUMBER - 1] = pos;
        temp->delta_pc = temp->reg[REG_NUMBER - 1];
        temp->pos = temp->reg[REG_NUMBER - 1];
        ++i;
        temp = temp->next;
    }
}