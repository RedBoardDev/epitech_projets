/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** exec_events_map.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void exec_events_not_fps_inde(events_t *all_events, events_t backup_events,
map_t *maps, beginning_t *begin)
{
    if (all_events->ctrl && all_events->mouse.move_x &&
    all_events->mouse_wheel.click)
        maps->angle.x += all_events->mouse.move_x / 2;
    if (!backup_events.ctrl && backup_events.mouse.move_x &&
    backup_events.mouse_wheel.click)
        maps->pos.x -= backup_events.mouse.move_x;
    if (!backup_events.ctrl && backup_events.mouse.move_y &&
    backup_events.mouse_wheel.click)
        maps->pos.y -= backup_events.mouse.move_y;
    events_zoom_and_selector_map(all_events, maps);
}

void exec_events_map(events_t *all_events, map_t *maps, beginning_t *begin)
{
    float delta = sfClock_getElapsedTime(begin->fps.clock).microseconds / 1000;
    float timer = begin->fps.timer + delta;
    events_t backup_events = *all_events;

    if (begin->save_file)
        return;
    check_limit_translation_map(maps, &backup_events);
    while (timer >= 8) {
        (all_events->ctrl && all_events->s) ? begin->save_file = true : 0;
        if (all_events->space) {
            free_int_array(maps->map_3d, maps->size.x);
            maps->map_3d = int_array_dup(maps->backup_3d, maps->size);
        }
        events_rotate_map(all_events, maps);
        events_modify_points_map(all_events, maps, begin);
        events_translate_map(backup_events, maps);
        timer -= 8;
    }
    exec_events_not_fps_inde(all_events, backup_events, maps, begin);
}
