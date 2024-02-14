/*
** EPITECH PROJECT, 2021
** B-PSU-101-MLH-1-1-navy-martin.d-herouville
** File description:
** set_vector_map.c
*/

#include "../include/my.h"
#include "../include/navy.h"
#include "../include/struct.h"

void set_vertical(players_t *player_struct, vector_t *vector_1,
vector_t *vector_2)
{
    for (int i = vector_1->y + 1; i < vector_2->y; ++i) {
        player_struct->map[i][vector_1->x] =
        player_struct->map[vector_1->y][vector_1->x];
    }
}

void set_horizontal(players_t *player_struct, vector_t *vector_1,
vector_t *vector_2)
{
    for (int i = vector_1->x + 1; i < vector_2->x; ++i) {
        player_struct->map[vector_1->y][i] =
        player_struct->map[vector_1->y][vector_1->x];
    }
}

void set_vector(vector_t *vector, char buff_1, char buff_2)
{
    vector->x = buff_1 - 65;
    vector->y = buff_2 - 49;
}
