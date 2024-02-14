/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** create_maps.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void create_3d_map(map_t *maps, sfVector2i size)
{
    int **res = malloc(sizeof(int *) * (size.x + 1));

    for (int i = 0; i < size.x; ++i) {
        res[i] = malloc(sizeof(int) * size.y + 1);
        for (int j = 0; j < size.y; ++j) {
            res[i][j] =
            (i == 0 || j == 0 || i == size.x - 1 || j == size.y - 1) ? -100 : 0;
        }
    }
    maps->map_3d = res;
}
