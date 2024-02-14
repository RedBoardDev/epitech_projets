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
#include <unistd.h>

int it_is_dead(int id, things_t *things)
{
    process_id_name_t *temp;

    temp = things->id_name;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp->is_dead;
        }
        temp = temp->next;
    }
}

void enum_process(things_t *things)
{
    process_t *temp;
    char inst;

    temp = things->all_process;
    while (temp != NULL) {
        if (it_is_dead(temp->reg[0], things) == 0) {
            inst = get_single_byte(temp, things);
            temp->to_exec = get_op_cycle(inst);
            treat_inst(inst, temp, things);
        }
        decrese_cycle(things);
        temp = temp->next;
    }
}

void check_process_life(things_t *things)
{
    process_id_name_t *temp;

    temp = things->id_name;
    while (temp != NULL) {
        if (temp->is_dead == 0 &&  temp->this_cycle == 0) temp->is_dead = 1;
        if (temp->is_dead == 0 &&  temp->this_cycle == 1 && temp->name) {
            things->nb_alive += 1;
            temp->this_cycle = 0;
        }
        temp = temp->next;
    }
}

void check_cycle(things_t *things, int cycle)
{
    if (cycle == things->next_check) {
        things->next_check += things->cycle_to_die;
        things->nb_alive = 0;
        check_process_life(things);
    }
}

void winner(things_t *things)
{
    process_id_name_t *temp;
    char str[1];

    temp = things->id_name;
    while (temp != NULL) {
        if (temp->is_dead == 0) {
            str[0] = temp->id + 48;
            write(1, "The player ", 11);
            write(1 , str, 1);
            write(1, " (", 2);
            write(1, temp->name, my_strlen(temp->name));
            write(1, ") has won.\n", 11);
            break;
        }
        temp = temp->next;
    }
}