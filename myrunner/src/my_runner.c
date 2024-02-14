/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** screensaver_main.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"
#include "../include/my.h"

void put_game(init_sfml_t *init_sfml, game_object_t *obj,
play_data_t *play_data, sound_ambiant_t *sound_ambiant) {
    move_parallax(init_sfml, obj);
    draw_sprite_walk(init_sfml, obj, play_data, sound_ambiant);
    play_data->score += init_sfml->speed_coef - 1;
    if (is_collided_sprite(obj))
        is_dead(play_data, sound_ambiant, obj, init_sfml);
    draw_lazer(init_sfml, obj);
    sfSprite_setPosition(obj[8].sprite, obj[8].pos);
    move_scientifist(init_sfml, &obj[8], obj[8].speed);
    manage_missile(init_sfml, obj);
    manage_draw_sprite(init_sfml, obj);
    put_score(play_data->score, init_sfml);
}

void free_sf(sound_ambiant_t *sound_ambiant, game_object_t *obj)
{
    sfMusic_destroy(sound_ambiant->main);
    sfMusic_destroy(sound_ambiant->rocket);
    sfMusic_destroy(sound_ambiant->walk);
    sfClock_destroy(obj->game_clock.fly_sprite);
    sfClock_destroy(obj->game_clock.lazer_sprite);
    sfClock_destroy(obj->game_clock.missile_sprite);
    for (int i = 0; i < OBJ_NBR; ++i) {
        sfClock_destroy(obj[i].clock);
    }
}

void my_runner(init_sfml_t *init_sfml, sfClock *clock)
{
    game_object_t *obj = malloc(sizeof(game_object_t) * OBJ_NBR);
    play_data_t play_data = init_play_data();
    sound_ambiant_t sound_ambiant;

    inits_sounds(&sound_ambiant);
    while (sfRenderWindow_isOpen(init_sfml->window)) {
        if (sfClock_getElapsedTime(init_sfml->clock).microseconds >= 1000) {
        sfClock_restart(init_sfml->clock);
            play_data.start ? put_game(init_sfml, obj, &play_data,
            &sound_ambiant) : put_main_menu(init_sfml, obj, &play_data,
            &sound_ambiant);
            analyse_events(init_sfml, obj, &play_data);
            function_sfml_whil(init_sfml, sfBlack);
        }
    }
    free(obj);
    free_sf(&sound_ambiant, obj);
    
}
