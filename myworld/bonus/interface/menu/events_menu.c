/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** events_menu.c
*/

#include "../../../include/my.h"
#include "../../../include/struct.h"
#include "../../../include/myworld.h"

void events_menu(beginning_t *begin, events_t *all_events,
load_button_t *load_button)
{
    if (begin->screen.load_menu && !all_events->ctrl &&
    all_events->mouse_wheel.down &&
    load_button[load_button[0].count - 1].pos.y > HEIGHT - 130) {
        for (int i = 0; i < load_button[0].count; ++i)
            load_button[i].pos.y -= 30;
    }
    if (begin->screen.load_menu && !all_events->ctrl &&
    all_events->mouse_wheel.up && load_button[0].pos.y < 130) {
        for (int i = 0; i < load_button[0].count; ++i)
            load_button[i].pos.y += 30;
    }
}
