/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** set_map.c
*/

#include "../include/my.h"
#include "../include/sokoban.h"

void print_map(char **map) {
    for (int i = 0; map[i] != NULL ; ++i) {
        printw(map[i]);
    }
}

int get_size_map(char *path)
{
    struct stat stats;

    stat(path, &stats);
    return (stats.st_size);
}

char **find_elements(char **map, maps_t *info_maps) {
    int i_storage = 0;
    int i_boxes = 0;
    
    for (int y = 0; map[y] != NULL; ++y) {
        for (int x = 0; map[y][x] != '\0'; ++x) {
            if (map[y][x] == 'P') {
                map[y][x] = ' ';
                info_maps->pos.y = y;
                info_maps->pos.x = x;
                info_maps->player_start.y = y;
                info_maps->player_start.x = x;
            }
            if (map[y][x] == 'O')
                ++i_storage;
            else if (map[y][x] == 'X')
                ++i_boxes;
        }
    }
    if (i_boxes != i_storage)
        my_exit(info_maps, 84);
    info_maps->count_storage = i_storage;
    return (map);
}

char **set_map(char *path, maps_t *info_maps) {
    char *buffer;
    unsigned int fd = 0;
    unsigned int rd = 0;
    int size = get_size_map(path);

    fd = open(path, O_RDONLY);
    buffer = malloc(sizeof(char *) * size + 1);
    buffer[size] = '\0';
    rd = read(fd, buffer, size);
    close(fd);
    info_maps->map  = my_str_to_word_array(buffer);
    info_maps->map  = find_elements(info_maps->map, info_maps);
    info_maps->save_map = my_arraydup(info_maps->map);
    free(buffer);
}
