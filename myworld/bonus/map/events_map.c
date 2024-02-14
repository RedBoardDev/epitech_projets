/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** events_map.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void events_zoom_and_selector_map(events_t *all_events, map_t *maps)
{
    if (all_events->page_down && maps->zoom > 0)
        --maps->zoom;
    if (all_events->page_up)
        ++maps->zoom;
    if (all_events->ctrl && all_events->mouse_wheel.up)
        ++maps->zoom;
    if (all_events->ctrl && all_events->mouse_wheel.down && maps->zoom > 0)
        --maps->zoom;
    if (all_events->p)
        ++maps->radius;
    if (all_events->m)
        --maps->radius;
    if (!all_events->ctrl && all_events->mouse_wheel.down)
        maps->radius -= 8;
    if (!all_events->ctrl && all_events->mouse_wheel.up)
        maps->radius += 8;
}

void events_rotate_map(events_t *all_events, map_t *maps)
{
    if (all_events->left)
        --maps->angle.x;
    if (all_events->right)
        ++maps->angle.x;
    if (all_events->down)
        --maps->angle.y;
    if (all_events->up)
        ++maps->angle.y;
}

void events_modify_points_map(events_t *all_events, map_t *maps,
beginning_t *begin)
{
    bool incidence = true;
    sfFloatRect collision_top = {0, 0, 470, 105};
    sfFloatRect collision_bottom = {1670, 908, 1920, 1080};

    if (all_events->mouse.left &&
    !check_mouse_on_one_button(all_events->mouse.pos, collision_top) &&
    ((begin->guiworld.toggle_move || begin->guiworld.toggle_rotate) ?
    !check_mouse_on_one_button(all_events->mouse.pos, collision_bottom) : 1))
        if (maps->painter)
            increase_decrease_points_zero(maps, all_events->mouse.pos, true);
        else
            increase_decrease_points_mouse(maps, all_events->mouse.pos, true);
    if (all_events->mouse.right)
        if (maps->painter)
            increase_decrease_points_zero(maps, all_events->mouse.pos, false);
        else
            increase_decrease_points_mouse(maps, all_events->mouse.pos, false);
    while (incidence)
        incidence = check_incidence(maps, all_events);
}

void events_translate_map(events_t backup_events, map_t *maps)
{
    if (!backup_events.ctrl && backup_events.z)
        maps->pos.y -= 5;
    if (!backup_events.ctrl && backup_events.s)
        maps->pos.y += 5;
    if (!backup_events.ctrl && backup_events.q)
        maps->pos.x -= 5;
    if (!backup_events.ctrl && backup_events.d)
        maps->pos.x += 5;
}
