/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** move.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"

int move_parallax(init_sfml_t *init_sfml, game_object_t *obj)
{
    for (int i = 0; i < 3; ++i) {
        obj[i].rect.left += obj[i].speed * init_sfml->speed_coef;
        if (obj[i].rect.left > 3840)
            obj[i].rect.left = 0;
        set_sprite_pos_texture(init_sfml, &obj[i]);
    }
    init_sfml->speed_coef <= 2 ? (init_sfml->speed_coef += 0.0004) : 0;
}

void sprite_scientifist(game_object_t *obj)
{
    if (get_timeClock(obj->clock) >= 200000) {
        for (int i = 0; i < 3; ++i)
            obj->rect.left = 6040 + 80;
        if (get_timeClock(obj->clock) >= 200000 * 2)
            sfClock_restart(obj->clock);
    } else
        obj->rect.left = 6040;
}

void move_scientifist(init_sfml_t *init_sfml, game_object_t *obj, float speed)
{
    sprite_scientifist(obj);
    obj->pos.x -= 16 * init_sfml->speed_coef;
    if (obj->pos.x <= -50)
        obj->pos.x = WIDTH + my_rand(1000, 10000);
    set_sprite_pos_texture(init_sfml, obj);
}
