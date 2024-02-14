/*
** EPITECH PROJECT, 2021
** B-PSU-200-MLH-2-1-mysokoban-thomas.ott
** File description:
** help.c
*/

#include "../include/my.h"
#include "../include/sokoban.h"

int help_message(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap file representing the warehouse map, containing '#'");
    my_putstr(" for walls,\n");
    my_putstr("\t'P' for the player, 'X' for boxes and 'O' for storage");
    my_putstr(" locations.\n");
    exit(0);
}
