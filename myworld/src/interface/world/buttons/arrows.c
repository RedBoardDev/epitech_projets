/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** arrows.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void button_arrow_down(world_t *world)
{
    world->maps.pos.y += 10;
}

void button_arrow_left(world_t *world)
{
    world->maps.pos.x -= 10;
}

void button_arrow_right(world_t *world)
{
    world->maps.pos.x += 10;
}

void button_arrow_up(world_t *world)
{
    world->maps.pos.y -= 10;
}
