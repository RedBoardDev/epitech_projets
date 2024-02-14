/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** events.c
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include "../include/structure.h"

int check_button(game_object_t obj, sfEvent event)
{
    if(event.mouseButton.x > obj.pos.x &&
        event.mouseButton.x < obj.pos.x + obj.rect.width &&
        event.mouseButton.y > obj.pos.y &&
        event.mouseButton.y < obj.pos.y + obj.rect.height)
        return (1);
    return (0);
}

int evt_move_block(sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyLeft)
            return (30);
        if (event.key.code == sfKeyRight)
            return (31);
        if (event.key.code == sfKeyDown)
            return (32);
        if (event.key.code == sfKeyUp)
            return (33);
    }
}

int analyse_events(init_sfml_t *init_sfml, game_object_t *obj, int mode)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(init_sfml->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(init_sfml->window);
        else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(init_sfml->window);
        if (event.type == sfEvtMouseButtonPressed && sfMouseLeft == event.key.code) {
            if (check_button(obj[1], event) && mode == 1)
                return (111);
            if (check_button(obj[2], event) && mode == 1)
                return (112);
            if (check_button(obj[3], event) && mode == 1)
                return (113);
        }
        if (mode == 2)
            return (evt_move_block(event));
    }
    return (0);
}
