/*
** EPITECH PROJECT, 2021
** B-PSU-200-MLH-2-1-mysokoban-thomas.ott
** File description:
** reset_map.c
*/

#include "../include/my.h"
#include "../include/sokoban.h"

void reset_map(maps_t *info_maps)
{
    info_maps->pos.y = info_maps->player_start.y;
    info_maps->pos.x = info_maps->player_start.x;
    my_freearray(info_maps->map);
    info_maps->map = my_arraydup(info_maps->save_map);
}

void check_reset(int ch, maps_t *info_maps)
{
    if (ch == 32)
        reset_map(info_maps);
}
