/*
** EPITECH PROJECT, 2021
** B-PSU-200-MLH-2-1-mysokoban-thomas.ott
** File description:
** win.c
*/

#include "../include/sokoban.h"

int check_storage(char **map, char **save_map, int count_storage)
{
    int i = 0;
    int ret = 1;

    for (int y = 0; map[y] != NULL && ret == 1; ++y) {
        for (int x = 0; map[y][x] != '\0' && ret == 1; ++x) {
            map[y][x] == 'X' && save_map[y][x] == 'O' ? ++i : 0;
            ret = (i == count_storage ? 0 : 1);
        }
    }
    return (ret);
}
