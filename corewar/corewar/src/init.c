/*
** EPITECH PROJECT, 2022
** B-CPE-201-MLH-2-1-corewar-thomas.ott
** File description:
** init
*/

#include "../include/corewar.h"

void init_flags(flags_t **flags, int i)
{
    flags[i]->load_address = -1;
    flags[i]->nbr_cycle = -1;
    flags[i]->prog_name = NULL;
    flags[i]->prog_number = -1;
}

void init_struct(debug_t *debug)
{
    debug->nbr_prog = 0;
    debug->nbr_flags = 0;
    debug->cur_load_address = 0;
    debug->cur_nbr_cycle = 0;
    debug->cur_prog_name = 0;
    debug->cur_prog_number = 0;
    debug->tot_load_address = 0;
    debug->tot_nbr_cycle = 0;
    debug->tot_prog_name = 0;
    debug->tot_prog_number = 0;
}

void reinit_struct(debug_t *debug)
{
    debug->cur_load_address = 0;
    debug->cur_nbr_cycle = 0;
    debug->cur_prog_name = 0;
    debug->cur_prog_number = 0;
}
