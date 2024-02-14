/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** rotate.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void button_rotate_left(world_t *world)
{
    world->maps.angle.x += 5;
}

void button_rotate_right(world_t *world)
{
    world->maps.angle.x -= 5;
}

void button_rotate_down(world_t *world)
{
    world->maps.angle.y -= 5;
}

void button_rotate_up(world_t *world)
{
    world->maps.angle.y += 5;
}
