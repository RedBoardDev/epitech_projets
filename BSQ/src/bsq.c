/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-bsbsq-thomas.ott
** File description:
** bsq.c
*/

#include "../include/my.h"
#include "../include/bsq.h"

int check_map(map_t *map)
{
    int size = map->size;
    int lenL = map->lenL;
    int stop = 0;
    int bigger = 0;

    for (int y = 0; y < size && stop == 0; ++y) {
        for (int x = 0; x < lenL && stop == 0; ++x) {
            check_char(map, x, y, '.') ? find_square(x, y, map) : 0;
            bigger = map->coords.bigger;
            stop = bigger >= map->lenL || bigger >= map->size ? 1 : 0;
        }
    }
}

int bsq(char *filepath)
{
    map_t map;
    int size = 0;
    int free_incr = 0;
    struct stat stats;

    stat(filepath, &stats);
    size = stats.st_size;
    free_incr = get_map(&map, filepath, size);
    check_map(&map);
    draw_square(&map);
    write(1, map.data, size - (map.len_nb + 1));
    free (map.data - free_incr);
}
