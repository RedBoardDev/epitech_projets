/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** collisions.c
*/

#include "../include/sokoban.h"

int check_collisions(int x, int y, int mouv, maps_t *info_maps) {
    if (info_maps->map[y][x] == '#')
        return (0);
    if (info_maps->map[y][x] == 'X')
        return (push_boxing(x, y, mouv, info_maps));
    return (1);
}
