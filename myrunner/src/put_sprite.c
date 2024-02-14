/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** put_sprite.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"
#include "../include/my.h"

void fly_sprite(game_object_t *obj)
{
    if (get_timeClock(obj->game_clock.fly_sprite) >= 120000) {
        obj[3].rect.top = 12;
        obj[3].rect.left = 6424;
        obj[3].rect.width = 124;
        obj[3].rect.height = 186;
        if (get_timeClock(obj->game_clock.fly_sprite) >= 120000 * 2)
            sfClock_restart(obj->game_clock.fly_sprite);
    } else {
        obj[3].rect.top = 12;
        obj[3].rect.left = 6424 + 134;
        obj[3].rect.width = 124;
        obj[3].rect.height = 186;
    }
}

int draw_sprite_walk(init_sfml_t *init_sfml, game_object_t *obj,
play_data_t *play_data, sound_ambiant_t *sound_ambiant)
{
    int nb = 3;
    int sprite_bool = 0;

    if (obj[3].jump == 1) {
        sfMusic_setVolume(sound_ambiant->rocket, 50);
        sprite_bool = 1;
        if (obj[3].pos.y >= 0)
            obj[3].pos_incr = -12;
        else
            obj[3].pos_incr = 0;
    } else
        sfMusic_setVolume(sound_ambiant->rocket, 0);
    obj[3].pos.y += obj[3].pos_incr;
    if (obj[3].pos.y < 820)
        obj[3].pos_incr = 12;
    if (obj[3].pos.y >= 820)
        obj[3].pos_incr = 0;
    if (get_timeClock(obj[3].clock) >= 100000) {
        play_data->sprite = play_data->sprite < 3 ? ++play_data->sprite : 0;
        sfClock_restart(obj[3].clock);
    }
    if (obj[nb].pos.y >= 820) {
        sfMusic_setVolume(sound_ambiant->walk, 100);
        switch (play_data->sprite) {
        case 0:
            obj[nb].rect.top = 12;
            obj[nb].rect.left = 5765;
            obj[nb].rect.width = 116;
            obj[nb].rect.height = 162;
            break;
        case 1:
            obj[nb].rect.top = 12;
            obj[nb].rect.left = 5895;
            obj[nb].rect.width = 118;
            obj[nb].rect.height = 168;
            break;
        case 2:
            obj[nb].rect.top = 12;
            obj[nb].rect.left = 6031;
            obj[nb].rect.width = 116;
            obj[nb].rect.height = 168;
            break;
        case 3:
            obj[nb].rect.top = 12;
            obj[nb].rect.left = 6158;
            obj[nb].rect.width = 124;
            obj[nb].rect.height = 162;
            break;
        default:
            break;
        }
    } else if (sprite_bool) {
            sfMusic_setVolume(sound_ambiant->walk, 0);
            fly_sprite(obj);
    } else {
            sfMusic_setVolume(sound_ambiant->walk, 0);
            obj[nb].rect.top = 12;
            obj[nb].rect.left = 6300;
            obj[nb].rect.width = 110;
            obj[nb].rect.height = 166;
    }
    set_sprite_pos_texture(init_sfml, &obj[nb]);
}

void manage_draw_sprite(init_sfml_t *init_sfml, game_object_t *obj)
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