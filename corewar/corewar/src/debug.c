/*
** EPITECH PROJECT, 2022
** B-CPE-201-MLH-2-1-corewar-thomas.ott
** File description:
** debug
*/

#include "../include/corewar.h"

int check_debug(debug_t *debug)
{
    if ((debug->tot_prog_name <= 1) || (debug->tot_prog_name > 4))
        return 84;
    if (debug->tot_nbr_cycle >= 2)
        return 84;
    if (debug->tot_load_address > debug->tot_prog_name)
        return 84;
    if (debug->tot_nbr_cycle > debug->tot_prog_name)
        return 84;
    if (debug->tot_prog_number > debug->tot_prog_name)
        return 84;
    return 0;
}

int check_cur_debug(debug_t *debug)
{
    if (debug->cur_nbr_cycle >= 2)
        return 84;
    if (debug->cur_load_address >= 2)
        return 84;
    if (debug->cur_prog_number >= 2)
        return 84;
    return 0;
}
