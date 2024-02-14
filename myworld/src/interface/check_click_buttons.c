/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** check_click_button.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void music_click(int i, sound_t sound)
{
    if (i != S_EXIT && i != S_SHUTDOWN)
        play_sound(sound.click, sound.volume);
}

bool check_click_one_button(world_t *world, int i)
{
    static const void (*functions[])(world_t *) = FUNCTIONS_BUTTONS;
    sfFloatRect collision;

    if (world->spritesheet[i].active) {
        collision = sfSprite_getGlobalBounds(world->spritesheet[i].sprite);
        if (check_mouse_on_one_button(world->all_events.mouse.pos, collision)) {
            music_click(i, world->begin.sound);
            world->begin.text.largeur_b = false;
            world->begin.text.hauteur_b = false;
            (*functions[i])(world);
            world->all_events.mouse.left = false;
            return (true);
        }
    }
    return (false);
}

bool check_click_load_buttons(world_t *world, int i)
{
    char *path = "maps/";
    sfFloatRect collision;

    collision = sfSprite_getGlobalBounds(world->load_button[i].sprite);
    if (check_mouse_on_one_button(world->all_events.mouse.pos, collision)) {
        path = my_strcat(path, world->load_button[i].name_file);
        load_map_runtime(path, &world->all_events, &world->maps);
        world->begin.load_map = false;
        world->begin.screen.world = true;
        world->all_events.mouse.left = false;
        world->begin.screen.load_menu = false;
        return (true);
    }
    return (false);
}

void check_click_buttons(world_t *world)
{
    if (world->all_events.mouse.left && world->begin.screen.soundbox)
        check_click_soundbox(world);
    if (!world->all_events.mouse.left_released)
        return;
    for (int i = 2; i < NBR_SPRITE; ++i)
        if (check_click_one_button(world, i))
            return;
    if (!world->begin.screen.load_menu)
        return;
    for (int i = 0; i < world->load_button[0].count; ++i)
        if (check_click_load_buttons(world, i))
            return;
}
