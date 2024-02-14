/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** boxes.c
*/

#include "../include/sokoban.h"

void send_storage(maps_t *info_maps, int y, int x) {
    if (info_maps->save_map[y][x] == 'O')
        info_maps->map[y][x] = 'O';
    else
        info_maps->map[y][x] = ' ';
}

void send_boxes(maps_t *info_maps, int y, int x) {
    info_maps->map[y][x] = 'X';
}

int push_boxing(int x, int y, int mouv, maps_t *info_maps) {
    int y2 = y;
    int x2 = x;

    if (mouv == 0)
        y2--;
    if (mouv == 1)
        y2++;
    if (mouv == 2)
        x2--;
    if (mouv == 3)
        x2++;
    if (info_maps->map[y2][x2] == '#' || info_maps->map[y2][x2] == 'X')
        return (0);
    send_storage(info_maps, y, x);
    send_boxes(info_maps, y2, x2);
    return (1);
}

int check_around(char **map, int y, int x) {
    int count = 0;

    if (map[y + 1][x + 1] == '#' && map[y - 1][x - 1] == '#')
        return (1);
    if (map[y + 1][x - 1] == '#' && map[y - 1][x + 1] == '#')
        return (1);
    return (0);
}

int check_blocking_boxes(char **map, int count_storage) {
    int count = 0;

    for (int y = 0; map[y] != NULL; ++y) {
        for (int x = 0; map[y][x] != '\0'; ++x) {
            if (map[y][x] == 'X') {
                count += check_around(map, y, x);
            }
        }
    }
    if (count >= count_storage)
        return (1);
    return (0);
}
