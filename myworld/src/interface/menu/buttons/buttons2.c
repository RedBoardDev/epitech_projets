/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** buttons2.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void nothing(world_t *world)
{
    return;
}

void button_hauteur(world_t *world)
{
    world->begin.text.hauteur_b = true;
}

void button_largeur(world_t *world)
{
    world->begin.text.largeur_b = true;
}

void button_sound(world_t *world)
{
    if (world->begin.screen.soundbox)
        world->begin.screen.soundbox = 0;
    else
        world->begin.screen.soundbox = 1;
}

void button_shutdown(world_t *world)
{
    sfRenderWindow_close(world->begin.window);
}
