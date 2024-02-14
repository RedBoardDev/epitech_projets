/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-BSQ-thomas.ott
** File description:
** draw_square.c
*/

#include "../include/bsq.h"
#include "../include/my.h"

void put_x(map_t *map, int lenL, int i, int j)
{
    int pointer = i + (lenL * j);

    if (map->data[pointer] == '\n')
        my_putchar('\n');
    else
        map->data[pointer] = 'x';
}

void draw_square(map_t *map)
{
    int bigger = map->coords.bigger;
    int bigger_y = map->coords.y + bigger;
    int bigger_x = map->coords.x + bigger;
    int lenL = map->lenL;

    for (int j = map->coords.y; j < bigger_y; ++j) {
        for (int i = map->coords.x; i < bigger_x; ++i) {
            put_x(map, lenL, i + j, j);
        }
    }
}
