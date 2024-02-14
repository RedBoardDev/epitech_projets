/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** check_incidence.c
*/

#include "../../../include/my.h"
#include "../../../include/struct.h"
#include "../../../include/myworld.h"

bool check_incidence_left(map_t *maps, events_t *all_events, int i, int j)
{
    bool check = false;

    if (all_events->mouse.left) {
        (i > 0 && maps->map_3d[i - 1][j] < maps->map_3d[i][j] - 4) ?
        ((maps->map_3d[i - 1][j] != -100 ? ++maps->map_3d[i - 1][j] : 0),
        check = true) : 0;
        (i < maps->size.x - 1 && maps->map_3d[i + 1][j] <
        maps->map_3d[i][j] - 4) ? ((maps->map_3d[i + 1][j] != -100 ?
        ++maps->map_3d[i + 1][j] : 0), check = true) : 0;
        (j > 0 && maps->map_3d[i][j - 1] < maps->map_3d[i][j] - 4) ?
        ((maps->map_3d[i][j - 1] != -100 ? ++maps->map_3d[i][j - 1] : 0),
        check = true) : 0;
        (j < maps->size.y - 1 && maps->map_3d[i][j + 1] <
        maps->map_3d[i][j] - 4) ? ((maps->map_3d[i][j + 1] != -100 ?
        ++maps->map_3d[i][j + 1] : 0), check = true) : 0;
    }
    return (check);
}

bool check_incidence_right(map_t *maps, events_t *all_events, int i, int j)
{
    bool check = false;
    if (all_events->mouse.right) {
        if (i != 0 && j != 0 && i != maps->size.x - 1 &&
        j != maps->size.y - 1) {
            (i > 0 && maps->map_3d[i - 1][j] > maps->map_3d[i][j] + 4) ?
            ((maps->map_3d[i - 1][j] != -100 ? --maps->map_3d[i - 1][j] : 0),
            check = true) : 0;
            (i < maps->size.x - 1 && maps->map_3d[i + 1][j] >
            maps->map_3d[i][j] + 4) ? ((maps->map_3d[i + 1][j] != -100 ?
            --maps->map_3d[i + 1][j] : 0), check = true) : 0;
            (j > 0 && maps->map_3d[i][j - 1] > maps->map_3d[i][j] + 4) ?
            ((maps->map_3d[i][j - 1] != -100 ? --maps->map_3d[i][j - 1] : 0),
            check = true) : 0;
            (j < maps->size.y - 1 && maps->map_3d[i][j + 1] >
            maps->map_3d[i][j] + 4) ? ((maps->map_3d[i][j + 1] != -100 ?
            --maps->map_3d[i][j + 1] : 0), check = true) : 0;
        }
    }
    return (check);
}

bool check_incidence(map_t *maps, events_t *all_events)
{
    bool check = false;

    for (int i = 0; i < maps->size.x; ++i) {
        for (int j = 0; j < maps->size.y; ++j) {
            check_incidence_left(maps, all_events, i, j);
            check_incidence_right(maps, all_events, i, j);
        }
    }
    return (check);
}
