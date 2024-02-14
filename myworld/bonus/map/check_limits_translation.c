/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** check_limits_translation.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void check_limit_translation_map1(map_t *maps, events_t *all_events)
{
    if (maps->backup_2d[0][maps->size.y - 1].iso.x < 0 &&
    maps->backup_2d[maps->size.x - 1][0].iso.x > WIDTH)
        return;
    if ((maps->backup_2d[0][maps->size.y - 1].iso.x < 0)) {
        all_events->q = false;
        all_events->mouse.move_x > 0 ? all_events->mouse.move_x = 0 : 0;
    }
    if ((maps->backup_2d[maps->size.x - 1][0].iso.x > WIDTH)) {
        all_events->d = false;
        all_events->mouse.move_x < 0 ? all_events->mouse.move_x = 0 : 0;
    }
}

void check_limit_translation_map2(map_t *maps, events_t *all_events)
{
    if (maps->backup_2d[maps->size.x - 1][maps->size.y - 1].iso.x < 0 &&
    maps->backup_2d[0][0].iso.x > WIDTH)
        return;
    if ((maps->backup_2d[maps->size.x - 1][maps->size.y - 1].iso.x < 0)) {
        all_events->q = false;
        all_events->mouse.move_x > 0 ? all_events->mouse.move_x = 0 : 0;
    }
    if ((maps->backup_2d[0][0].iso.x > WIDTH)) {
        all_events->d = false;
        all_events->mouse.move_x < 0 ? all_events->mouse.move_x = 0 : 0;
    }
}

void check_limit_translation_map3(map_t *maps, events_t *all_events)
{
    if (maps->backup_2d[maps->size.x - 1][0].iso.x < 0 &&
    maps->backup_2d[0][maps->size.y - 1].iso.x > WIDTH)
        return;
    if ((maps->backup_2d[maps->size.x - 1][0].iso.x < 0)) {
        all_events->q = false;
        all_events->mouse.move_x > 0 ? all_events->mouse.move_x = 0 : 0;
    }
    if ((maps->backup_2d[0][maps->size.y - 1].iso.x > WIDTH)) {
        all_events->d = false;
        all_events->mouse.move_x < 0 ? all_events->mouse.move_x = 0 : 0;
    }
}

void check_limit_translation_map4(map_t *maps, events_t *all_events)
{
    if (maps->backup_2d[0][0].iso.x < 0 &&
    maps->backup_2d[maps->size.x - 1][maps->size.y - 1].iso.x > WIDTH)
        return;
    if ((maps->backup_2d[0][0].iso.x < 0)) {
        all_events->q = false;
        all_events->mouse.move_x > 0 ? all_events->mouse.move_x = 0 : 0;
    }
    if ((maps->backup_2d[maps->size.x - 1][maps->size.y - 1].iso.x > WIDTH)) {
        all_events->d = false;
        all_events->mouse.move_x < 0 ? all_events->mouse.move_x = 0 : 0;
    }
}

void check_limit_translation_map(map_t *maps, events_t *all_events)
{
    if ((maps->angle.x % 360 >= 315 && maps->angle.x % 360 <= 360) ||
    (maps->angle.x % 360 >= 0 && maps->angle.x % 360 < 45))
        check_limit_translation_map1(maps, all_events);
    if (maps->angle.x % 360 >= 45 && maps->angle.x % 360 < 135)
        check_limit_translation_map2(maps, all_events);
    if (maps->angle.x % 360 >= 135 && maps->angle.x % 360 < 225)
        check_limit_translation_map3(maps, all_events);
    if (maps->angle.x % 360 >= 225 && maps->angle.x % 360 < 315)
        check_limit_translation_map4(maps, all_events);
}
