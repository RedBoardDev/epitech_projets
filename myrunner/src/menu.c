/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** menu.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"

void put_main_menu(init_sfml_t *init_sfml, game_object_t *obj,
play_data_t *play_data, sound_ambiant_t *sound_ambiant)
{
    sfMusic_setVolume(sound_ambiant->rocket, 0);
    sfMusic_setVolume(sound_ambiant->walk, 0);
    inits_obj(obj, init_sfml);
    set_sprite_pos_texture(init_sfml, &obj[7]);
    sfRenderWindow_drawSprite(init_sfml->window, obj[7].sprite, NULL);
    put_score(play_data->score, init_sfml);
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        play_data->start = 1;
        play_data->score = 0;
        sfMusic_play(sound_ambiant->main);
    }
    init_sfml->speed_coef = 1;
}
