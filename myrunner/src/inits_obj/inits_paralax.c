/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** inits_paralax.c
*/

#include "../../include/my_runner.h"
#include "../../include/structur.h"

void inits_paralax(game_object_t *obj, init_sfml_t *init_sfml)
{
    obj[0].rect.top = 0;
    obj[0].rect.left = 0;
    obj[0].rect.width = 1920;
    obj[0].rect.height = 1080;
    obj[0].speed = 6;
    obj[0].clock = sfClock_create();
    obj[1].rect.top = 1080;
    obj[1].rect.left = 0;
    obj[1].rect.width = 1920;
    obj[1].rect.height = 1080;
    obj[1].speed = 10;
    obj[1].clock = sfClock_create();
    obj[2].rect.top = 2160;
    obj[2].rect.left = 0;
    obj[2].rect.width = 1920;
    obj[2].rect.height = 1080;
    obj[2].speed = 14;
    obj[2].clock = sfClock_create();
}
