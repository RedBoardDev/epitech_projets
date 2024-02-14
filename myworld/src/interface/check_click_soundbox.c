/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** check_click_soundbox.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void check_click_soundbox_toggle_volume(world_t *world)
{
    sfFloatRect collision =
    sfSprite_getGlobalBounds(world->spritesheet[S_SOUND_POTENTIO].sprite);

    collision.width = collision.height;
    if (check_mouse_on_one_button(world->all_events.mouse.pos, collision)) {
        if (world->begin.sound.volume) {
            world->begin.sound.volume_backup = world->begin.sound.volume;
            world->begin.sound.volume = 0;
            world->spritesheet[S_SOUND_SELECT].pos.x = WIDTH - 380;
        } else {
            world->begin.sound.volume = world->begin.sound.volume_backup;
            world->spritesheet[S_SOUND_SELECT].pos.x =
            (WIDTH - 380) + (world->begin.sound.volume * 2.6);
        }
        world->all_events.mouse.left = false;
    }
}

void check_click_soundbox(world_t *world)
{
    sfFloatRect collision =
    sfSprite_getGlobalBounds(world->spritesheet[S_SOUND_SELECT].sprite);

    if (!world->all_events.mouse.left_released &&
    check_mouse_on_one_button(world->all_events.mouse.pos, collision)) {
        world->begin.screen.soundbox = 2;
        world->all_events.mouse.left = false;
        return;
    }
    check_click_soundbox_toggle_volume(world);
}
