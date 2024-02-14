/*
** EPITECH PROJECT, 2021
** B-PSU-200-MLH-2-1-mysokoban-thomas.ott
** File description:
** my_exit.c
*/

#include "../include/sokoban.h"
#include "../include/my.h"

void my_exit(maps_t *info_maps, int ret)
{
    usleep(200000);
    endwin();
    my_freearray(info_maps->map);
    my_freearray(info_maps->save_map);
    exit(ret);
}

void my_exit_check_map(maps_t *info_maps, int ret)
{
    my_freearray(info_maps->map);
    exit(ret);
}
