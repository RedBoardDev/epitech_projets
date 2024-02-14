/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** mouse.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void events_mouse_pressed(beginning_t *begin, sfEvent event,
events_t *all_events)
{
    if (sfMouseLeft == event.key.code) {
        all_events->mouse.left = true;
        all_events->mouse.pos = sfMouse_getPositionRenderWindow(begin->window);
        begin->text.largeur_b = false;
        begin->text.hauteur_b = false;
    }
    if (sfMouseRight == event.key.code) {
        all_events->mouse.right = true;
        all_events->mouse.pos = sfMouse_getPositionRenderWindow(begin->window);
    }
    if (sfMouseMiddle == event.key.code)
        all_events->mouse_wheel.click = true;
}

void events_mouse_released(beginning_t *begin, sfEvent event,
events_t *all_events)
{
    if (sfMouseLeft == event.key.code) {
        all_events->mouse.left = false;
        all_events->mouse.left_released = true;
        all_events->mouse.pos = sfMouse_getPositionRenderWindow(begin->window);
        if (begin->screen.soundbox == 2)
                begin->screen.soundbox = 1;
    }
    if (sfMouseRight == event.key.code) {
        all_events->mouse.right = false;
        all_events->mouse.pos = sfMouse_getPositionRenderWindow(begin->window);
    }
    if (sfMouseMiddle == event.key.code)
        all_events->mouse_wheel.click = false;
}

void events_scroll_wheel(sfEvent event, events_t *all_events)
{
    if (event.mouseWheelScroll.delta > 0)
        all_events->mouse_wheel.up = true;
    else
        all_events->mouse_wheel.up = false;
    if (event.mouseWheelScroll.delta < 0)
        all_events->mouse_wheel.down = true;
    else
        all_events->mouse_wheel.down = false;
}

void event_mouse_moved(sfEvent event, events_t *all_events)
{
    if (all_events->mouse.pos.x != event.mouseMove.x)
        all_events->mouse.move_x = all_events->mouse.pos.x - event.mouseMove.x;
    if (all_events->mouse.pos.y != event.mouseMove.y)
        all_events->mouse.move_y = all_events->mouse.pos.y - event.mouseMove.y;
}
