/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** key_pressed.c
*/

#include "../include/my.h"
#include "../include/sokoban.h"

void move_item(int ch, maps_t *info_maps)
{
    int x = info_maps->pos.x;
    int y = info_maps->pos.y;

    if (ch == KEY_UP)
        y -= check_collisions(x, y - 1, 0, info_maps);
    if (ch == KEY_DOWN)
        y += check_collisions(x, y + 1, 1, info_maps);
    if (ch == KEY_LEFT)
        x -= check_collisions(x - 1, y, 2, info_maps);
    if (ch == KEY_RIGHT)
        x += check_collisions(x + 1, y, 3, info_maps);
    info_maps->pos.x = x;
    info_maps->pos.y = y;
}
