/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** toggle.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void button_toggle_move(world_t *world)
{
    world->begin.guiworld.toggle_move = (world->begin.guiworld.toggle_move) ?
    false : true;
    world->begin.guiworld.toggle_rotate = false;
}

void button_toggle_rotate(world_t *world)
{
    world->begin.guiworld.toggle_rotate = (world->begin.guiworld.toggle_rotate)
    ? false : true;
    world->begin.guiworld.toggle_move = false;
}

void button_painter(world_t *world)
{
    world->begin.guiworld.painter = (world->begin.guiworld.painter) ?
    false : true;
    world->maps.painter = (world->maps.painter) ? false : true;
}

void button_rotate_360(world_t *world)
{
    world->begin.guiworld.rotate_360 = (world->begin.guiworld.rotate_360) ?
    false : true;
}
