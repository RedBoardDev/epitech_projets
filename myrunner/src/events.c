/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** events.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"

int events_close_window(init_sfml_t *init_sfml)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(init_sfml->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(init_sfml->window);
        else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(init_sfml->window);
    }
}

int analyse_events(init_sfml_t *init_sfml, game_object_t *obj,
play_data_t *play_data)
{
    sfEvent event;

    int jump = obj[3].jump;
    while (sfRenderWindow_pollEvent(init_sfml->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(init_sfml->window);
        else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(init_sfml->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace &&
            jump != 1)
            jump = 1;
        else if (event.type == sfEvtKeyReleased &&
        event.key.code == sfKeySpace)
            play_data->start ? (jump = 0) : 0;
    }
    obj[3].jump = jump;
    return (0);
}
