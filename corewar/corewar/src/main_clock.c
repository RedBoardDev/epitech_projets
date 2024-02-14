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

void main_clock(things_t *things)
{
    int cycle = 0;

    for (int i = 0; i != -1 ; ++i) {
        enum_process(things);
        check_cycle(things, cycle);
        if (things->nb_alive == 1) {
            winner(things);
            break;
        }
        usleep(5000);
        ++cycle;
    }
}