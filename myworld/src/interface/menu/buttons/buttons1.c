/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** menu_buttons.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void button_create_map(world_t *world)
{
    if (world->begin.screen.main_menu) {
        world->begin.screen.main_menu = false;
        world->begin.screen.create_menu = true;
        return;
    } else if (world->begin.screen.create_menu) {
        world->begin.screen.create_menu = false;
        world->begin.screen.world = true;
        world->begin.init_map = true;
    }
}

void button_load_map(world_t *world)
{
    if (world->begin.screen.main_menu) {
        world->begin.screen.main_menu = false;
        world->begin.screen.load_menu = true;
        world->begin.get_file = true;
    }
}

void button_exit(world_t *world)
{
    sfRenderWindow_close(world->begin.window);
}

void button_back_to_menu(world_t *world)
{
    world->begin.screen.create_menu = false;
    world->begin.screen.load_menu = false;
    world->begin.screen.world = false;
    world->begin.screen.main_menu = true;
}
