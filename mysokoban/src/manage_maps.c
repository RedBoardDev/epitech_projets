/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** set_map.c
*/

#include "../include/my.h"
#include "../include/sokoban.h"

int get_size_file(char *path)
{
    struct stat stats;

    stat(path, &stats);
    return (stats.st_size);
}

int check_elements(char c, maps_t *info_maps, int y, int x)
{
    if (c == 'P') {
        info_maps->pos.y = y;
        info_maps->pos.x = x;
        info_maps->player_start.y = y;
        info_maps->player_start.x = x;
        return (1);
    } else if (c == 32 || c == 10 || c == 35 || c == 88 || c == 79)
        return (1);
    return (0);
}

char **set_elements_into_maps(char **map, int y, int x, maps_t *info_maps)
{
    if (!check_elements(map[y][x], info_maps, y, x))
        my_exit_check_map(info_maps, 84);
    if (map[y][x] == 'P')
        map[y][x] = ' ';
    return (map);
}

char **find_elements(char **map, maps_t *info_maps)
{
    int y = 0;
    int x = 0;
    int i_boxes = 0;
    int i_storage = 0;

    for (; map[y] != NULL; ++y) {
        for (; map[y][x] != '\0'; ++x) {
            map = set_elements_into_maps(map, y, x, info_maps);
            map[y][x] == 'O' ? ++i_storage :
            (map[y][x] == 'X' ? ++i_boxes : 0);
        }
        info_maps->size_map.x = x;
        x = 0;
    }
    info_maps->size_map.y = y;
    if (i_boxes != i_storage)
        my_exit_check_map(info_maps, 84);
    info_maps->count_storage = i_storage;
    return (map);
}

int set_map(char *path, maps_t *info_maps)
{
    char *buffer;
    unsigned int fd = 0;
    unsigned int rd = 0;
    int size = get_size_file(path);

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (84);
    buffer = malloc(sizeof(char *) * size + 1);
    buffer[size] = '\0';
    rd = read(fd, buffer, size);
    if (rd == -1)
        return (84);
    close(fd);
    info_maps->map = my_str_to_word_array(buffer);
    info_maps->map = find_elements(info_maps->map, info_maps);
    info_maps->save_map = my_arraydup(info_maps->map);
    free(buffer);
    return (0);
}
