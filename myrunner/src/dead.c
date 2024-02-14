/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** dead.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"
#include "../include/my.h"

void manage_draw_sprite_dead(init_sfml_t *init_sfml, game_object_t *obj)
{
    for (int i = 0; i < OBJ_NBR; ++i)
        sfRenderWindow_drawSprite(init_sfml->window, obj[i].sprite, NULL);
    for (int i = 0; i < 3; ++i)
        sfRenderWindow_drawSprite(init_sfml->window, obj[i].sprite, NULL);
    sfRenderWindow_drawSprite(init_sfml->window, obj[8].sprite, NULL);
    for (int i = 3; i < 7; ++i)
        sfRenderWindow_drawSprite(init_sfml->window, obj[i].sprite, NULL);
    sfRenderWindow_drawSprite(init_sfml->window, obj[9].sprite, NULL);
}

void my_sleep(int time_in_millisecond, init_sfml_t *init_sfml)
{
    sfClock *clock = sfClock_create();
    while (get_timeClock(clock) < (time_in_millisecond * 1000))
        events_close_window(init_sfml);
}

void set_pos_object(game_object_t *obj, int top, int left, int width)
{
    obj->rect.top = top;
    obj->rect.left = left;
    obj->rect.width = width;
}

void boucle_norme(game_object_t *obj, init_sfml_t *init_sfml, bool type)
{
    if (type == true) {
        for (int i = 0; i <= 10 && obj[3].pos.y <= 820; ++i) {
            obj[3].pos.y += 10;
            set_sprite_pos_texture(init_sfml, &obj[3]);
            manage_draw_sprite_dead(init_sfml, obj);
            function_sfml_whil(init_sfml, sfBlack);
            my_sleep(15, init_sfml);
        }
    } else {
        while (obj[3].pos.y <= 820) {
            obj[3].pos.y += 14;
            set_sprite_pos_texture(init_sfml, &obj[3]);
            manage_draw_sprite_dead(init_sfml, obj);
            function_sfml_whil(init_sfml, sfBlack);
            my_sleep(10, init_sfml);
        }
    }
}


void is_dead(play_data_t *play_data, sound_ambiant_t *sound_ambiant,
game_object_t *obj, init_sfml_t *init_sfml)
{
    sfMusic *die = sfMusic_createFromFile("ressources/sounds/die_player.ogg");

    sfMusic_stop(sound_ambiant->main);
    sfMusic_play(die);
    set_pos_object(&obj[3], 218, 5903, 105);
    obj[3].rect.height = 145;
    play_data->start = 0;
    set_sprite_pos_texture(init_sfml, &obj[3]);
    manage_draw_sprite_dead(init_sfml, obj);
    function_sfml_whil(init_sfml, sfBlack);
    boucle_norme(obj, init_sfml, true);
    set_pos_object(&obj[3], 192, 5774, 97);
    obj[3].rect.height = 172;
    play_data->start = 0;
    set_sprite_pos_texture(init_sfml, &obj[3]);
    manage_draw_sprite_dead(init_sfml, obj);
    function_sfml_whil(init_sfml, sfBlack);
    boucle_norme(obj, init_sfml, false);
    my_sleep(500, init_sfml);
}
