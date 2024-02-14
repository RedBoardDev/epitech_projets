/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** save.c
*/

#include "../../../../include/my.h"
#include "../../../../include/struct.h"
#include "../../../../include/myworld.h"

void button_write_filename(world_t *world)
{
    world->begin.text.filename_save_b = world->begin.text.filename_save_b
    ? false : true;
}

void button_save_window(world_t *world)
{
    char *filename;

    if (world->begin.text.filename_save[0] == '\0')
        return;
    filename = my_strcat(my_strcat("../maps/",
    world->begin.text.filename_save), ".myw");
    world->begin.text.filename_save_b = false;
    world->begin.save_file = false;
    save_file(filename, &world->maps);
}

void button_cancel_window(world_t *world)
{
    world->begin.text.filename_save_b = false;
    world->begin.save_file = false;
}
