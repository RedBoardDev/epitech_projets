/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-navy-martin.d-herouville
** File description:
** print_help.c
*/

#include "../include/my.h"

void print_help(void)
{
    my_putstr("USAGE\n    ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    first_player_pid: only for the 2nd player.");
    my_putstr(" pid of the first player.\n");
    my_putstr("    navy_positions: file representing");
    my_putstr(" the positions of the ships.\n");
}
