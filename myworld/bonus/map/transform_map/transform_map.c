/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** move_map.c
*/

#include "../../../include/my.h"
#include "../../../include/struct.h"
#include "../../../include/myworld.h"

void check_one_point_mouse(map_t *maps, sfVector2i pos_mouse, bool up,
sfVector2i index)
{
    int i = index.x;
    int j = index.y;

    if (((int)maps->map_2d[i][j].iso.x > pos_mouse.x - maps->radius &&
    (int)maps->map_2d[i][j].iso.x < pos_mouse.x + maps->radius) &&
    ((int)maps->map_2d[i][j].iso.y > pos_mouse.y - maps->radius &&
    (int)maps->map_2d[i][j].iso.y < pos_mouse.y + maps->radius))
        if (up)
            maps->map_3d[i][j] != -100 ? ++maps->map_3d[i][j] : 0;
        else
            maps->map_3d[i][j] > -49 ? --maps->map_3d[i][j] : 0;
}

void increase_decrease_points_mouse(map_t *maps, sfVector2i pos_mouse, bool up)
{
    for (int i = 0; i < maps->size.x; ++i)
        for (int j = 0; j < maps->size.y; ++j)
            check_one_point_mouse(maps, pos_mouse, up, (sfVector2i){i, j});
}

void check_one_point_by_zero(map_t *maps, sfVector2i pos_mouse, bool up,
sfVector2i index)
{
    int i = index.x;
    int j = index.y;

    if (((int)maps->backup_2d[i][j].iso.x > pos_mouse.x - maps->radius &&
    (int)maps->backup_2d[i][j].iso.x < pos_mouse.x + maps->radius) &&
    ((int)maps->backup_2d[i][j].iso.y > pos_mouse.y - maps->radius &&
    (int)maps->backup_2d[i][j].iso.y < pos_mouse.y + maps->radius)) {
        if (up)
            maps->map_3d[i][j] != -100 ? ++maps->map_3d[i][j] : 0;
        else
            maps->map_3d[i][j] > -49 ? --maps->map_3d[i][j] : 0;
    }
}

void increase_decrease_points_zero(map_t *maps, sfVector2i pos_mouse, bool up)
{
    for (int i = 0; i < maps->size.x; ++i)
        for (int j = 0; j < maps->size.y; ++j)
            check_one_point_by_zero(maps, pos_mouse, up, (sfVector2i){i, j});
}
