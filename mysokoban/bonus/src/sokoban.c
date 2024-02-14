/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** sokoban.c
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include "../include/structure.h"

void my_exit(maps_t *info_maps, int ret)
{
    my_freearray(info_maps->map);
    my_freearray(info_maps->save_map);
    exit(ret);
}

int sokoban(init_sfml_t *init_sfml) {
    int ch;
    maps_t info_maps;
    play_data_t play_data;
    game_object_t *obj = malloc(sizeof(game_object_t) * OBJ_NBR);
    sfMusic *music = sfMusic_createFromFile("ressources/music/main_song.ogg");

    sfMusic_setLoop(music, true);
    sfMusic_play(music);
    play_data.start = 0;
    inits_obj(obj, init_sfml);
    while (sfRenderWindow_isOpen(init_sfml->window)) {
        draw_sprite(init_sfml, &obj[0]);
        play_data.start ? game(&play_data, init_sfml, obj, &info_maps) : menu(&play_data, init_sfml, obj, &info_maps);
        function_sfml_whil(init_sfml, sfBlack);
    }
}
