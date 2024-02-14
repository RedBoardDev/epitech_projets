/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-BSQ-thomas.ott
** File description:
** keep_map.c
*/

#include "../include/my.h"
#include "../include/bsq.h"

int len_ligne(char *data)
{
    int i = 0;

    for (; data[i] != '\n'; ++i);
    return (i);
}

int is_norme(unsigned int fd, unsigned int rd, char *str, map_t *map)
{
    char buffer_1[10];
    int len_line = 0;

    (fd = open(str, O_RDONLY)) == -1 ? exit(84) : 0;
    (rd = read(fd, &buffer_1, 10)) <= 0 ? exit(84) : 0;
    error_number_column(buffer_1);
    len_line = my_getnbr(buffer_1);
    map->len_nb = intlen(len_line, 0);
    return (len_line);
}

int get_map(map_t *map, char *str, int size)
{
    char *buffer;
    unsigned int fd = 0;
    unsigned int rd = 0;
    int len_line = is_norme(fd, rd, str, map);

    fd = open(str, O_RDONLY);
    buffer = malloc(sizeof(char *) * size + 1);
    rd = read(fd, buffer, size);
    buffer[rd] = '\0';
    !my_strlen(map->data = buffer + (map->len_nb + 1)) ? exit (84) : 0;
    map->lenL = len_ligne(map->data);
    map->size = (rd - (map->len_nb + 1)) / map->lenL;
    error_same_line_size(map->data, map->size, map->len_nb) != len_line ?
    exit(84) : 0;
    rd <= map->len_nb + 1 ? exit(84) : 0;
    map->coords.bigger = 0;
    map->len_nb = map->len_nb;
    return (map->len_nb + 1);
}
