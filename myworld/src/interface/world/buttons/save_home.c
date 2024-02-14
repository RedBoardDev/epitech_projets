/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** buttons_gui_world.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void button_home(world_t *world)
{
    world->begin.screen.world = false;
    world->begin.screen.main_menu = true;
}

void button_save(world_t *world)
{
    world->begin.save_file = true;
}
