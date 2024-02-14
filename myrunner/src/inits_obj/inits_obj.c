/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** inits_obj.c
*/

#include "../../include/my_runner.h"
#include "../../include/structur.h"

game_object_t *create_object(sfVector2f pos, sfIntRect rect, sfTexture *texture)
{
    game_object_t *game_object;

    game_object->sprite = sfSprite_create();
    game_object->pos = pos;
    game_object->rect = rect;
}

void inits_missile(game_object_t *obj, init_sfml_t *init_sfml)
{
    obj[9].rect.top = 500;
    obj[9].rect.left = 1920 * 3;
    obj[9].rect.width = 120;
    obj[9].rect.height = 43;
    obj[9].speed = 20;
    obj[9].pos.x = -200;
    obj[9].pos.y = 0;
    obj[9].clock = sfClock_create();
}

void start_menu(game_object_t *obj, init_sfml_t *init_sfml)
{
    obj[7].rect.top = 2160;
    obj[7].rect.left = 1920 * 3;
    obj[7].rect.width = 1920;
    obj[7].rect.height = 1080;
    obj[7].speed = 0;
    obj[7].clock = sfClock_create();
}

void inits_obj(game_object_t *obj, init_sfml_t *init_sfml)
{
    inits_paralax(obj, init_sfml);
    inits_player(obj, init_sfml);
    inits_lazer(obj, init_sfml);
    start_menu(obj, init_sfml);
    inits_scientifists(obj, init_sfml);
    inits_missile(obj, init_sfml);
    for (int i = 0; i < OBJ_NBR; ++i) {
        obj[i].sprite = sfSprite_create();
        sfSprite_setTexture(obj[i].sprite, init_sfml->texture, sfFalse);
        sfSprite_setTextureRect(obj[i].sprite, obj[i].rect);
    }
    obj->game_clock.lazer_sprite = sfClock_create();
    obj->game_clock.missile_sprite = sfClock_create();
    obj->game_clock.fly_sprite = sfClock_create();
}
