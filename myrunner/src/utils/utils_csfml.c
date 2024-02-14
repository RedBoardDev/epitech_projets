/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** utils_csfml.c
*/

#include "../../include/my_runner.h"
#include "../../include/structur.h"

int my_rand(int min, int max)
{
    int rand_int = min + rand() % (max - min);

    return (rand_int);
}

sfUint8 *framebuffer_create(int w, int h)
{
    return (malloc(sizeof(sfUint8) * (w * h * 4)));
}

void function_sfml_whil(init_sfml_t *init_sfml, sfColor c)
{
    sfRenderWindow_display(init_sfml->window);
}

sfInt64 get_timeClock(sfClock *clock)
{
    return (sfClock_getElapsedTime(clock).microseconds);
}

void set_sprite_pos_texture(init_sfml_t *init_sfml, game_object_t *obj)
{
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, obj->pos);
}
