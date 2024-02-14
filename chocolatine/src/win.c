/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** win.c
*/

#include "../include/sokoban.h"

int check_storage(maps_t *info_maps) {
    int i = 0;

    for (int y = 0; info_maps->map[y] != NULL; ++y) {
        for (int x = 0; info_maps->map[y][x] != '\0'; ++x) {
            if (info_maps->map[y][x] == 'X' && info_maps->save_map[y][x] == 'O')
                ++i;
            if (i == info_maps->count_storage) {
                return (0);
            }
        }
    }
    return (1);
}
