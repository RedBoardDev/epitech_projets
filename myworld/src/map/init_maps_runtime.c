/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** init_maps_runtime.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void reset_variables_map(map_t *maps)
{
    maps->angle.x = 0;
    maps->angle.y = 0;
    maps->zoom = ZOOM;
    maps->pos.x = POS_X;
    maps->pos.y = POS_Y;
    maps->radius = 50;
}

void create_malloc_all_maps(map_t *maps)
{
    maps->map_2d = malloc(sizeof(point_t *) * maps->size.x);
    for (int i = 0; i < maps->size.x; ++i)
        maps->map_2d[i] = malloc(sizeof(point_t) * maps->size.y);
    maps->backup_2d = malloc(sizeof(point_t *) * maps->size.x);
    for (int i = 0; i < maps->size.x; ++i)
        maps->backup_2d[i] = malloc(sizeof(point_t) * maps->size.y);
    maps->backup_3d = int_array_dup(maps->map_3d, maps->size);
    create_2d_map(maps, maps->size);
}

void load_map_runtime(char *filepath, events_t *all_events, map_t *maps)
{
    load_file(filepath, maps);
    create_malloc_all_maps(maps);
}

void init_display_folder_with_maps(world_t *world)
{
    free(world->load_button);
    world->load_button = init_open_folder_maps(&world->begin);
    world->begin.get_file = false;
    reset_variables_map(&world->maps);
}

void init_empty_map_with_size(beginning_t *begin, events_t *all_events,
map_t *maps)
{
    sfVector2i size = {my_atoi(begin->text.hauteur) + 3,
    my_atoi(begin->text.largeur) + 3};

    if (size.x == 3)
        ++size.x;
    if (size.y == 3)
        ++size.y;
    reset_variables_map(maps);
    maps->size = size;
    create_3d_map(maps, maps->size);
    create_malloc_all_maps(maps);
}
