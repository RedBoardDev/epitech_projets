/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-navy-martin.d-herouville
** File description:
** set_map.c
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "../include/struct.h"

void check_direction(players_t *player_struct, char *buffer,
vector_t *vector_1, vector_t *vector_2)
{
    if (vector_1->x == vector_2->x)
        set_vertical(player_struct, vector_1, vector_2);
    else
        set_horizontal(player_struct, vector_1, vector_2);
}

int set_file_map(players_t *player_struct)
{
    char *buffer = malloc(sizeof(char) * 33);
    int fd = open(player_struct->filepath, O_RDONLY);
    int r = read(fd, buffer, 33);
    vector_t vector_1;
    vector_t vector_2;
    int calc = 0;

    if (fd == -1 || r == 0 || error_handling_map(buffer) == 84)
        return (84);
    for (int i = 0; i < 4; ++i) {
        calc = i * 8 + 2;
        set_vector(&vector_1, buffer[calc], buffer[calc + 1]);
        player_struct->map[vector_1.y][vector_1.x] = buffer[calc - 2];
        set_vector(&vector_2, buffer[calc + 3], buffer[calc + 4]);
        player_struct->map[vector_2.y][vector_2.x] = buffer[calc - 2];
        check_direction(player_struct, buffer, &vector_1, &vector_2);
    }
    close(fd);
    return (0);
}

void modify_map(players_t *enemy_map, bool hit, char *arg)
{
    int letter = arg[0] - 65;
    int number = arg[1] - 49;

    if (hit)
        enemy_map->map[number][letter] = 'x';
    else if (enemy_map->map[number][letter] != 'x')
        enemy_map->map[number][letter] = 'o';
}
