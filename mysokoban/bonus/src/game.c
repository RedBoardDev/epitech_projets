/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** game.c
*/

#include "../include/sokoban.h"
#include "../include/structure.h"

void game(play_data_t *play_data, init_sfml_t *init_sfml, game_object_t *obj,
maps_t *info_maps)
{
    int ret = 0;
    int x = info_maps->pos.x;
    int y = info_maps->pos.y;
    sfVector2i pos_map;

    for (int y = 0; info_maps->map[y] != NULL; ++y) {
        for (int x = 0; info_maps->map[y][x] != '\0'; ++x) {
            pos_map.x = x;
            pos_map.y = y;
            set_block_img(init_sfml, obj, pos_map, info_maps->map[y][x]);
        }
    }
    ret = analyse_events(init_sfml, obj, 2);
    if (info_maps->map[y][x] == 'P' && info_maps->save_map[y][x] == 'O')
        info_maps->map[y][x] = info_maps->save_map[y][x];
    else
        info_maps->map[y][x] = ' ';
    if (ret == 33)
        y -= check_collisions(x, y - 1, 0, info_maps);
    if (ret == 32)
        y += check_collisions(x, y + 1, 1, info_maps);
    if (ret == 30)
        x -= check_collisions(x - 1, y, 2, info_maps);
    if (ret == 31)
        x += check_collisions(x + 1, y, 3, info_maps);
    info_maps->pos.x = x;
    info_maps->pos.y = y;
    info_maps->map[y][x] = 'P';
    if (!check_storage(info_maps))
        play_data->start = 0;

}
