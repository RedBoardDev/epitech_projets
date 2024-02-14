/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-BSQ-thomas.ott
** File description:
** gestor_square.c
*/

#include "../include/bsq.h"

int check_char(map_t *map, int i, int j, char c)
{
    return (map->data[i + (map->lenL * j) + j] == c);
}

int check_square(map_t *map, int x, int y, int len_square)
{
    int char_stop = 0;

    for (int j = y; j <= y + len_square && char_stop == 0; ++j)
        for (int i = x; i <= x + len_square && char_stop == 0; ++i)
            char_stop = check_char(map, i, j, 'o') ? 1 : 0;
    return (char_stop ? 0 : 1);
}

void find_square(int x, int y, map_t *map)
{
    int len_square = 1;
    int bool = 1;

    while (bool) {
        if (len_square >= map->lenL || len_square >= map->size)
            bool = 0;
        if (x + len_square < map->lenL && y + len_square < map->size) {
            bool = check_square(map, x, y, len_square);
            bool ? len_square++ : 0;
        } else
            bool = 0;
    }
    if (map->coords.bigger < len_square) {
        map->coords.bigger = len_square;
        map->coords.x = x;
        map->coords.y = y;
    }
}