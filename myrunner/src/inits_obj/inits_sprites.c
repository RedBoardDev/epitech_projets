/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** inits_sprites.c
*/

#include "../../include/my_runner.h"
#include "../../include/structur.h"

void inits_lazer(game_object_t *obj, init_sfml_t *init_sfml)
{
    set_pos_object(&obj[4], 383, 5760, 246);
    obj[4].rect.height = 78;
    obj[4].pos.x = WIDTH + my_rand(100, 800);
    obj[4].jump = 0;
    set_pos_object(&obj[5], 383, 5760, 246);
    obj[5].rect.height = 78;
    obj[5].pos.x = WIDTH + my_rand(1200, 2400);
    set_pos_object(&obj[6], 383, 5760, 246);
    obj[6].rect.height = 78;
    obj[6].pos.x = WIDTH + my_rand(2800, 4000);
    for (int i = 0; i < 3; ++i) {
        obj[4 + i].clock = sfClock_create();
        obj[4 + i].speed = 14;
        obj[4 + i].pos.y = my_rand(86, HEIGHT - 200);
        obj[4 + 1].pos_incr = 0;
    }

}

void inits_scientifists(game_object_t *obj, init_sfml_t *init_sfml)
{
    obj[8].rect.top = 240;
    obj[8].rect.left = 6040;
    obj[8].rect.width = 80;
    obj[8].rect.height = 123;
    obj[8].speed = 1;
    obj[8].pos.x = WIDTH + my_rand(800, 1800);
    obj[8].pos.y = 755;
    obj[8].clock = sfClock_create();
}

void inits_player(game_object_t *obj, init_sfml_t *init_sfml)
{
    obj[3].rect.top = 12;
    obj[3].rect.left = 5765;
    obj[3].rect.width = 116;
    obj[3].rect.height = 162;
    obj[3].speed = 0;
    obj[3].pos.x = WIDTH / 5;
    obj[3].pos.y = 820;
    obj[3].pos_incr = 0;
    obj[3].clock = sfClock_create();
    obj[3].jump = 0;
}