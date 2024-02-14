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

void valid_this_cycle(things_t *things, int id)
{
    process_id_name_t *temp;

    temp = things->id_name;
    while (temp != NULL) {
        if (id == temp->id && temp->is_dead == 0) temp->this_cycle = 1;
        temp = temp->next;
    }
}

void live(char inst, process_t *process, things_t *things, op_t op)
{
    int proc = get_adress_bytes(1, things, process);
    char c[1];

    c[0] = proc + 48;
    write(1, "The player ", 11);
    write(1, c, 1);
    write(1, " (", 2);
    write(1, get_name_from_id(proc, things->id_name),
my_strlen(get_name_from_id(proc, things->id_name)));
    write(1, ") is alive.\n", 12);
    process->delta_pc += 4;
    things->nb_live += 1;
    valid_this_cycle(things, proc);
}